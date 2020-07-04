package com.company;

import java.io.*;
import java.lang.reflect.Array;
import java.nio.file.FileAlreadyExistsException;
import java.util.ArrayList;
import java.util.EmptyStackException;

public class PrimeNumbers implements Numbers, Serializable
{
    private static final long serialVersionUID = 0001L;
        public int liczba;
        ArrayList<Integer> Liczby_pierwsze;
        public int indeks;

    public PrimeNumbers()
    {
        liczba = 1;
        Liczby_pierwsze = new ArrayList<Integer>();
        indeks = 0;
    }

    private boolean CzyPierwsza(int x)
    {
        if (x < 2) return false;

        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0) return false;
        }

        return true;
    }

    public int next()
    {
        if (eos())
        {
            System.out.println("Przekroczony zakres!");
        }
        else liczba++;

        while (CzyPierwsza(liczba) == false)
        {
            if (eos())
            {
                System.out.println("Przekroczony zakres!");
                break;
             }
            else
            {
                liczba++;
            }
        }
        Liczby_pierwsze.add(liczba);
        indeks++;
        return liczba;
    }

    public boolean eos()
    {
        if(Integer.MAX_VALUE < liczba)
        {
            return true;
        }
        else return false;
    }

    public void reset()
    {
        liczba = 1;
        Liczby_pierwsze.clear();
        indeks=0;
    }

    public void ShowAll()
    {
        for(int i = 0; i<indeks; i++)
        {
            System.out.println(Liczby_pierwsze.get(i));
        }
    }
}
