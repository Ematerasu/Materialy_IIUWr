package com.company;

public class Main {

    public static void main(String[] args)
    {
        Dodaj test = new Dodaj(new Stala(4), new Zmienna("x", 12));
        Odejmij test2 = new Odejmij(test, new Zmienna("y", 1));
        Mnozenie test3 = new Mnozenie(new Stala(6), new Stala(7));
        Dzielenie test4 = new Dzielenie(test3, test2);

        System.out.println(test4.ToString());
        System.out.println(test4.oblicz());

        Potegowanie test5 = new Potegowanie(new Stala(5), new Stala( 4));

        System.out.println(test5.oblicz());
        System.out.println(test5.ToString());

        Modulo test6 = new Modulo(new Stala(12), new Stala(5));
        System.out.println(test6.oblicz());
        System.out.println(test6.ToString());

    }
}
