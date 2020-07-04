package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class StopnieWojskowe
{
    List<Stopien> zbior_rang;

    public StopnieWojskowe()
    {
        zbior_rang = new ArrayList<Stopien>();
    }
    public void Dodaj(Stopien rank)
    {
        zbior_rang.add(rank);
        Collections.sort(zbior_rang, Collections.reverseOrder());
    }

    public Stopien Pobierz()
    {
        if(zbior_rang.size()==0)
        {
            System.out.println("Nie ma elementow do usuniecia");
            return null;
        }

        Stopien temp = zbior_rang.get(0);
        zbior_rang.remove(0);
        return temp;
    }

    public void Wypisz()
    {
        for(int i = zbior_rang.size()-1; i>=0;i--) //kolejnosc od najwyzszej rangi do najnizszej
        {
            System.out.println(zbior_rang.get(i));
        }
    }

}
