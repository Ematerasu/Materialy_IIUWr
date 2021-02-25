package Samotnik;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MenuBar extends JMenuBar implements ActionListener{
    private JMenu gra, ruchy, ustawienia, pomoc;
    private JMenuItem graNowa, graKoniec;
    private JMenuItem ruchyGora, ruchyDol, ruchyPrawo, ruchyLewo;
    private JRadioButtonMenuItem british, european;
    private JMenuItem oGrze, oAplikacji;

    private  MainMenu window;

    private Samotnik samotnikIns;

    public MenuBar(MainMenu window) {
        this.window = window;
        samotnikIns = Samotnik.getInstance();
        gra = new JMenu("Gra");
        graNowa = new JMenuItem("Nowa");
        graKoniec = new JMenuItem("Koniec");
        gra.add(graNowa);
        gra.add(graKoniec);

        graNowa.addActionListener(this);
        graKoniec.addActionListener(this);

        ruchy = new JMenu("Ruchy");
        ruchyGora = new JMenuItem("Ruch w gore");
        ruchyDol = new JMenuItem("Ruch w dol");
        ruchyPrawo = new JMenuItem("Ruch w prawo");
        ruchyLewo = new JMenuItem("Ruch w lewo");
        ruchy.add(ruchyGora);
        ruchy.add(ruchyDol);
        ruchy.add(ruchyLewo);
        ruchy.add(ruchyPrawo);

        ruchyGora.addActionListener(this);
        ruchyDol.addActionListener(this);
        ruchyPrawo.addActionListener(this);
        ruchyLewo.addActionListener(this);

        ustawienia = new JMenu("Ustawienia");
        british = new JRadioButtonMenuItem("Wersja brytyjska");
        european = new JRadioButtonMenuItem("Wersja europejska");
        british.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                samotnikIns.setVersion("ENGLISH");
            }
        });

        european.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                samotnikIns.setVersion("EUROPEAN");
            }
        });

        ustawienia.add(british);
        ustawienia.add(european);

        pomoc = new JMenu("Pomoc");
        oGrze = new JMenuItem("O grze");
        oAplikacji = new JMenuItem("O aplikacji");
        pomoc.add(oGrze);
        pomoc.add(oAplikacji);

        oGrze.addActionListener(this);
        oAplikacji.addActionListener(this);

        add(gra);
        add(ruchy);
        add(ustawienia);
        add(Box.createHorizontalGlue());
        add(pomoc);

        setCommand();

    }

    private void setCommand() {
        ruchyPrawo.setActionCommand("RIGHT");
        ruchyDol.setActionCommand("DOWN");
        ruchyLewo.setActionCommand("LEFT");
        ruchyGora.setActionCommand("UP");

        graNowa.setActionCommand("NEW_GAME");
        graKoniec.setActionCommand("END_GAME");
        oGrze.setActionCommand("HELP-ABOUT_GAME");
        oAplikacji.setActionCommand("HELP-ABOUT_APP");
    }

    public void actionPerformed(ActionEvent e){
        switch(e.getActionCommand()){
            case "RIGHT":
                samotnikIns.MovePiece(samotnikIns.getxSelected(), samotnikIns.getySelected(), samotnikIns.getxSelected()+2, samotnikIns.getySelected());
                break;
            case "DOWN":
                samotnikIns.MovePiece(samotnikIns.getxSelected(), samotnikIns.getySelected(), samotnikIns.getxSelected(), samotnikIns.getySelected()+2);
                break;
            case "LEFT":
                samotnikIns.MovePiece(samotnikIns.getxSelected(), samotnikIns.getySelected(), samotnikIns.getxSelected()-2, samotnikIns.getySelected());
                break;
            case "UP":
                samotnikIns.MovePiece(samotnikIns.getxSelected(), samotnikIns.getySelected(), samotnikIns.getxSelected(), samotnikIns.getySelected()-2);
                break;
            case "NEW_GAME":
                samotnikIns.newGame();
                window.dispose();
                window = new MainMenu();
                window.Run();
                break;
            case "END_GAME":
                window.dispose();
                break;
            case "HELP-ABOUT_GAME":
                JDialog modalFrame = new JDialog(window, "O grze", true);
                modalFrame.setSize(200, 200);
                modalFrame.setResizable(false);
                JPanel panel = new JPanel();
                JLabel text1 = new JLabel("Gra logiczna rozgrywana przez jedna osobe na planszy majacej 33 lub 37 pol. Rzekomo powstala na rozkaz Ludwika XIV.", SwingConstants.CENTER);
                JLabel text2 = new JLabel("Zyskala popularnosc we Francji w XVII wieku, pozniej w innych krajach (w tym takze w Polsce). Bardziej uproszczone gry byly znane wczesniej w starozytnym Rzymie.", SwingConstants.CENTER);
                JLabel text3 = new JLabel("Gra dostepna jest w wersji Europejskiej (37 pionkow) oraz Brytyjskiej (33 pionki)", SwingConstants.CENTER);
                JLabel text4 = new JLabel("Celem gry jest zostawienie na planszy jak najmniejszej liczby pionkow. Idealnym rozwiazaniem jest pozostawienie jednego pionka, najlepiej w centrum.", SwingConstants.CENTER);
                JLabel text5 = new JLabel("Pionka bije sie przeskakujac go w pionie lub w poziomie. Nie mozna poruszac sie na ukos oraz nie mozna bic kilku pionkow w jednym ruchu.", SwingConstants.CENTER);
                panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
                panel.add(text1);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text2);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text3);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text4);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text5);
                modalFrame.getContentPane().add(panel);
                modalFrame.pack();
                modalFrame.setLocationRelativeTo(null);
                modalFrame.setVisible(true);
                break;
            case "HELP-ABOUT_APP":
                modalFrame = new JDialog(window, "O aplikacji", true);
                modalFrame.setSize(200, 200);
                modalFrame.setResizable(false);
                panel = new JPanel();
                text1 = new JLabel("Prosta aplikacja pozwalajaca zagrac w Samotnika");
                text2 = new JLabel("By ruszyc pionkiem kliknij na nim lewym przyciskiem myszki");
                text3 = new JLabel("Gdy zmieni kolor na czzerwony to znaczy ze jest zaznaczony");
                text4 = new JLabel("Teraz by nim ruszyc kliknij w puste pole na ktorym chcesz go postawic, albo kliknij prawy przycisk myszy i wybierz ruch");
                panel.setLayout(new BoxLayout(panel, BoxLayout.PAGE_AXIS));
                panel.add(text1);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text2);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text3);
                panel.add(Box.createRigidArea(new Dimension(5, 5)));
                panel.add(text4);

                modalFrame.getContentPane().add(panel);
                modalFrame.pack();
                modalFrame.setLocationRelativeTo(null);
                modalFrame.setVisible(true);
                break;
        }
    }
}
