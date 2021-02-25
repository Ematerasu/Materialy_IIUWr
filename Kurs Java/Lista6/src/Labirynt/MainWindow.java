package Labirynt;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MainWindow extends Frame {

    public Canvas board;

    public MainWindow() {
        setTitle("Labirynt");

        board = new Board(10);
        add(board);

        setSize(1000, 1000);
        setLocation(400, 50);
        setVisible(true);
        setResizable(false);
        addWindowListener((new WindowAdapter(){
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        }));

    }

    public Canvas GetPanel() {
        return board;
    }

}
