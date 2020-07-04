package com.company;

class Porucznik implements Stopien
{
    private int val = 18;

    public int get_stopien()
    {
        return this.val;
    }

    public int compareTo(Stopien Porownanie)
    {
        return Integer.compare(Porownanie.get_stopien(), this.get_stopien());
    }
}