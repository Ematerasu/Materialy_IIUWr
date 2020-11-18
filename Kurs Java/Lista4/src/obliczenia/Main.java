package obliczenia;
import struktury.*;

import java.io.IOException;

public class Main {

    public static void main(String[] args) throws Exception {

        Zmienna.zbiorZmiennych.Wstaw(new Para("x", 2));
        Zmienna.zbiorZmiennych.Wstaw(new Para("y", 4));

        Wyrazenie w1 = new Dodawanie(
                new Liczba(7),
                new Mnozenie(
                        new Zmienna("x"),
                        new Liczba(5)
                )
        );

        Wyrazenie w2 = new Dodawanie(new Liczba(3), new Liczba(5));
        Wyrazenie w3 = new Mnozenie(new ZmianaZnaku(new Odejmowanie(new Liczba(2), new Zmienna("x"))), new Liczba(7));
        Wyrazenie w4 = new Dzielenie(new Odejmowanie(new Mnozenie(new Liczba(3), new Liczba(11)), new Liczba(1)), new Dodawanie(new Liczba(7), new Liczba(5)));
        Wyrazenie w5 = new Minimum(new Mnozenie(new Dodawanie(new Zmienna("x"), new Liczba(13)), new Zmienna("x")),
                new Modulo(new Odejmowanie(new Liczba(1), new Zmienna("x")), new Liczba(2)));
        Wyrazenie w6 = new Dodawanie(new Potegowanie(new Liczba(2), new Liczba(5)),
                new Mnozenie(new Zmienna("x"), new Mniejsze(new LogDyskretny(new Liczba(2), new Zmienna("y")), new Liczba(20))));


        System.out.println(w1.toString() + " = " + w1.oblicz());
        System.out.println(w2.toString() + " = " + w2.oblicz());
        System.out.println(w3.toString() + " = " + w3.oblicz());
        System.out.println(w4.toString() + " = " + w4.oblicz());
        System.out.println(w5.toString() + " = " + w5.oblicz());
        System.out.println(w6.toString() + " = " + w6.oblicz()+"\n\n\n\n");

        try {
            Instrukcja i1 = new InstrukcjaBlokowa(new DeklaracjaZmiennej("n"), new InstrukcjaCzytania("n"),
                    new InstrukcjaWarunkowa(new Mniejsze(new Zmienna("n"), new Liczba(2)), new InstrukcjaPisania(new Liczba(0)), new InstrukcjaBlokowa(
                            new DeklaracjaZmiennej("p"), new InstrukcjaPrzypisania(new Zmienna("p"), new Liczba(2)), new DeklaracjaZmiennej("wyn"),
                            new InstrukcjaPetli(new MniejszeRowne(new Mnozenie(new Zmienna("p"), new Zmienna("p")), new Zmienna("n")), new InstrukcjaBlokowa(
                                    new InstrukcjaWarunkowa(new Rowne(new Modulo(new Zmienna("n"), new Zmienna("p")), new Liczba(0)), new InstrukcjaBlokowa(
                                            new InstrukcjaPrzypisania(new Zmienna("wyn"), new Zmienna("p")), new InstrukcjaPrzypisania(new Zmienna("p"), new Zmienna("n")))),
                                    new InstrukcjaPrzypisania(new Zmienna("p"), new Dodawanie(new Zmienna("p"), new Liczba(1)))
                            )),
                            new InstrukcjaWarunkowa(new Wieksze(new Zmienna("wyn"), new Liczba(0)), new InstrukcjaPisania(new Liczba(0)), new InstrukcjaPisania(new Liczba(1)))
                    )));
            System.out.println(i1.toString()+"\n\n");
            i1.wykonaj();
        }
        catch(Exception e) {
            throw new IOException("Blad!");
        }

    }
}
