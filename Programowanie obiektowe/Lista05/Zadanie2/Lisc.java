package com.company;

import java.util.Hashtable;

class Zmienna extends Wyrazenie
{
    String nazwa_zmiennej;
    Hashtable<String, Integer> wartosci_zmiennych = new Hashtable();

    public Zmienna(String nazwa_zmiennej, int wartosc_zmiennej)
    {
        this.nazwa_zmiennej = nazwa_zmiennej;
        wartosci_zmiennych.put(nazwa_zmiennej,wartosc_zmiennej);
    }

    public int oblicz()
    {
        return wartosci_zmiennych.get(nazwa_zmiennej);
    }

    public String ToString()
    {
        return this.nazwa_zmiennej;
    }
}

class Stala extends Wyrazenie
{
    int Wartosc;

    public Stala(int val)
    {
        Wartosc=val;
    }

    public int oblicz()
    {
        return Wartosc;
    }

    public String ToString()
    {
        return "" + Wartosc + "";
    }

}
