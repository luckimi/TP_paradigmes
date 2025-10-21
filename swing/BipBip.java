package swing;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class BipBip extends JFrame {// fenêtre principale

    JScrollPane scroll;
    JTextArea text;
    JPanel bas;
    JButton button1, button2, close;
    private static final long serialVersionUID = 1L;

    public static void main(String argv[]) {
        new BipBip();
    }

    public BipBip() {
        setLayout(new BorderLayout());
        add (scroll = new JScrollPane(text = new JTextArea(10,50)), BorderLayout.CENTER);
        add (bas = new JPanel(), BorderLayout.SOUTH);
        bas.add(button1 = new JButton("Hello"));
        bas.add(button2 = new JButton("End"));
        bas.add(close = new JButton("Close"));
        button1.addActionListener(new DoItListener());
        button2.addActionListener(new PrintListener());
        close.addActionListener(new CloseListener());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class DoItListener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            text.append("hello world\n");
        }
    }

    class PrintListener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            text.append("goodbye\n");
        }
    }

    class CloseListener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
}
