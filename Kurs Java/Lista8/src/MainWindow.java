import javax.swing.*;

public class MainWindow extends JFrame{
    public MainWindow() {
        setTitle("Kalendarz");
        setSize(800, 800);

        Panel mainPanel = new Panel();
        getContentPane().add(mainPanel);

        ToolBar bottomPanel = new ToolBar();
        getContentPane().add(bottomPanel);

    }

    public void Run(){
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
    }
}
