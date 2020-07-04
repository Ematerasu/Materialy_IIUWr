package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.List;
import java.util.ArrayList;

public class Main {

    List<Pojazd> pojazd = new ArrayList<Pojazd>();

    public static void main(String[] args)
    {
        Main start = new Main();
        start.run();
    }

    public void run()
    {
        JFrame frame = new JFrame("Pojazdy");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container kontener = frame.getContentPane();
        GridLayout layout = new GridLayout(3, 2);
        kontener.setLayout(layout);

        JLabel typ = new JLabel("Typ Pojazdu(Samochod/Tramwaj)");
        kontener.add(typ);
        JTextField podaj_typ = new JTextField(10);
        kontener.add(podaj_typ);

        JLabel nazwa = new JLabel("Nazwa samochodu/tramwaju");
        kontener.add(nazwa);
        JTextField podaj_nazwe = new JTextField(30);
        kontener.add(podaj_nazwe);

        JLabel moc = new JLabel("Moc samochodu/Ilosc_miejsc w tramwaju");
        kontener.add(moc);
        JTextField podaj_moc = new JTextField(10);
        kontener.add(podaj_moc);

        JLabel rocznik = new JLabel("Rocznik");
        kontener.add(rocznik);
        JTextField podaj_rocznik = new JTextField(5);
        kontener.add(podaj_rocznik);

        JLabel info = new JLabel("");
        kontener.add(info);


        JButton load = new JButton("Wczytaj");
        load.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                FileInputStream file = null;
                ObjectInputStream in = null;

                List<Pojazd> lista = null;

                try
                {
                    file = new FileInputStream("pojazdy.txt");
                    in = new ObjectInputStream(file);
                    lista = (List<Pojazd>) in.readObject();
                    info.setText("Wczytano. Zawartosc w konsoli.");
                }
                catch (FileNotFoundException err)
                {
                    info.setText("Brak pliku.");
                    err.printStackTrace();
                }
                catch (IOException err)
                {
                    err.printStackTrace();
                }
                catch (ClassNotFoundException err)
                {
                    err.printStackTrace();
                }
                for(Pojazd obj : lista)
                    System.out.println(obj.ToString());
            }
        });
        kontener.add(load);

        JButton save = new JButton("Zapisz");
        save.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                try
                {
                    FileOutputStream file= new FileOutputStream("pojazdy.txt");
                    ObjectOutputStream out= new ObjectOutputStream(file);
                    out.writeObject(pojazd);
                    out.close();
                    info.setText("\nZapisuje...");
                }
                catch(IOException ioe)
                {
                    info.setText("Blad zapisu.");
                    ioe.printStackTrace();
                }
            }
        }
        );
        kontener.add(save);

        JButton add = new JButton("Dodaj");
        add.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                String type = podaj_typ.getText();
                String name_vin = podaj_nazwe.getText();
                String power_ilosc = podaj_moc.getText();
                String year = podaj_rocznik.getText();
                podaj_nazwe.setText("");
                podaj_moc.setText("");
                podaj_rocznik.setText("");
                podaj_typ.setText("");

                if(type.equals("Samochod"))
                {
                    pojazd.add(new Samochod(name_vin, power_ilosc, year));
                    info.setText("Dodaje samochod " + name_vin + " z roku " + year + " o mocy " + power_ilosc + "KM");
                }

                if(type.equals("Tramwaj"))
                {
                    pojazd.add(new Tramwaj(name_vin, power_ilosc, year));
                    info.setText("Dodaje tramwaj " + name_vin + " z roku " + year + ". ilosc miejsc: " + power_ilosc);
                }
            }
        });
        kontener.add(add);

        frame.pack();
        frame.setVisible(true);
    }
}
