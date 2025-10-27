package swing;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Screen extends JFrame {// fenêtre principale

    JScrollPane scroll;
    JMenuBar menuBar;
    JMenu menu;
    JToolBar tool;
    JTextArea text;
    JPanel bas;
    Action hello, end, close;
    private static final long serialVersionUID = 1L;

    public static void main(String argv[]) {
        new Screen();
    }

    public Screen() {
        System.setProperty("apple.laf.useScreenMenuBar", "true");
        setLayout(new BorderLayout());

        add(scroll = new JScrollPane(text = new JTextArea(10, 50)), BorderLayout.CENTER);

        hello = new Hello();
        end = new End();
        close = new Close();

        menuBar = new JMenuBar();
        menu = new JMenu("Actions");
        menu.add(new JMenuItem(hello));
        menu.add(new JMenuItem(end));
        menu.add(new JMenuItem(close));
        menuBar.add(menu);
        setJMenuBar(menuBar);

        tool = new JToolBar();
        tool.add(hello);
        tool.add(end);
        tool.add(close);
        add(tool, BorderLayout.NORTH);

        add(bas = new JPanel(), BorderLayout.SOUTH);
        bas.add(new JButton(hello));
        bas.add(new JButton(end));
        bas.add(new JButton(close));

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class Hello extends AbstractAction {

        public Hello() {
            super("Hello");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            text.append("hello world\n");
        }
    }
    class End extends AbstractAction {

        public End() {
            super("End");
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            text.append("goodbye\n");
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
