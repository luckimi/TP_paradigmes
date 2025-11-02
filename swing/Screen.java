package swing;

import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import javax.swing.*;

public class Screen extends JFrame {

    private static final long serialVersionUID = 1L;

    JScrollPane scroll;
    JTextArea text;
    JPanel bottomPanel;
    JToolBar toolBar;
    JMenuBar menuBar;
    JMenu menu;
    Action find, play, close, send;
    Client client;

    public static void main(String[] args) {
        SwingUtilities.invokeLater(Screen::new);
    }

    public Screen() {
        System.setProperty("apple.laf.useScreenMenuBar", "true");
        setLayout(new BorderLayout());

        // Text area (read/write) for commands and responses
        text = new JTextArea(20, 50);
        scroll = new JScrollPane(text);
        add(scroll, BorderLayout.CENTER);

        // Connect to server
        try {
            client = new Client("localhost", 3331);
            text.append("Connected to server on port 3331\n");
        } catch (IOException e) {
            text.append("Could not connect to server: " + e.getMessage() + "\n");
        }

        // Actions
        find = new Find();
        play = new Play();
        close = new Close();
        send = new AbstractAction("Send") {
            @Override
            public void actionPerformed(ActionEvent e) {
                sendLastLine(); // send last typed line without printing
            }
        };

        // Menu
        menuBar = new JMenuBar();
        menu = new JMenu("Actions");
        menu.add(new JMenuItem(find));
        menu.add(new JMenuItem(play));
        menu.add(new JMenuItem(close));
        menu.add(new JMenuItem(send));
        menuBar.add(menu);
        setJMenuBar(menuBar);

        // Toolbar (top)
        toolBar = new JToolBar();
        toolBar.add(find);
        toolBar.add(play);
        toolBar.add(close);
        toolBar.add(send);
        add(toolBar, BorderLayout.NORTH);

        // Bottom panel with buttons (below text area)
        bottomPanel = new JPanel();
        bottomPanel.add(new JButton(find));
        bottomPanel.add(new JButton(play));
        bottomPanel.add(new JButton(close));
        bottomPanel.add(new JButton(send));
        add(bottomPanel, BorderLayout.SOUTH);

        // Press Enter in text area to send the last line
        text.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    e.consume(); // prevent new line
                    sendLastLine();
                }
            }
        });

        setTitle("Screen Client");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    // Send message to server with option to display in text area
    private void sendToServer(String msg, boolean showInText) {
        if (showInText) {
            text.append(msg + "\n");  // just write the word for buttons
        }

        new Thread(() -> {
            String response = client.send(msg);
            SwingUtilities.invokeLater(() -> {
                if (response != null) {
                    text.append("\nResponse: " + response + "\n");
                } else {
                    text.append("\n[No response or connection lost]\n");
                }
                text.setCaretPosition(text.getDocument().getLength());
            });
        }).start();
    }

    // Overload for default behavior
    private void sendToServer(String msg) {
        sendToServer(msg, true);
    }

    // Send last line typed in text area (Send button / Enter)
    private void sendLastLine() {
        String content = text.getText();
        String[] lines = content.split("\n");
        if (lines.length == 0) {
            return;
        }

        String lastLine = lines[lines.length - 1];
        if (lastLine.trim().isEmpty()) {
            return;
        }

        sendToServer(lastLine, false); // false = don't write extra
    }

    // Actions
    class Find extends AbstractAction {

        public Find() {
            super("Find");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            text.append("find "); // only display
            text.setCaretPosition(text.getDocument().getLength());
        }
    }

    class Play extends AbstractAction {

        public Play() {
            super("Play");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            text.append("play "); // only display
            text.setCaretPosition(text.getDocument().getLength());
        }
    }

    class Close extends AbstractAction {

        public Close() {
            super("Close");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
