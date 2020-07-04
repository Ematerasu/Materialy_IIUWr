package com.company;

import java.io.Serializable;

public class Tramwaj extends Pojazd implements Serializable
{
    private static final long serialVersionUID = 0003L;
    String ilosc_miejsc;
    String nazwa;

    Tramwaj(String il, String name, String year)
    {
        ilosc_miejsc = il;
        nazwa = name;
        rocznik = year;
    }

    String ToString()
    {
        return "Tramwaj o pojemnosci " + ilosc_miejsc + ", wykonany w roku " + rocznik + " o nazwie " + nazwa;
    }
}
