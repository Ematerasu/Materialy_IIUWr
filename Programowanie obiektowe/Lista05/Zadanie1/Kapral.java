package com.company;

class Kapral implements Stopien
{
    private int val = 3;

    public int get_stopien()
    {
        return this.val;
    }

    public int compareTo(Stopien Porownanie)
    {
        return Integer.compare(Porownanie.get_stopien(), this.get_stopien());
    }
}
