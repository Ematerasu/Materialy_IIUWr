package com.company;

class Sierzant implements Stopien
{
    private int val = 6;

    public int get_stopien()
    {
        return this.val;
    }

    public int compareTo(Stopien Porownanie)
    {
        return Integer.compare(Porownanie.get_stopien(), this.get_stopien());
    }
}