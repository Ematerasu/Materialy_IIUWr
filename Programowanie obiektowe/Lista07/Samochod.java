package com.company;

import java.io.Serializable;

public class Samochod extends Pojazd implements Serializable
{
    private static final long serialVersionUID = 0002L;
    String moc;
    String nazwa;

    Samochod(String name, String power, String year)
    {
        nazwa = name;
        moc = power;
        rocznik = year;
    }

    String ToString()
    {
        return "Samochod o nazwie " + nazwa + ", wykonany w roku " + rocznik + " o mocy " + moc + "KM";
    }
}
