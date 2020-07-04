package com.company;

class Dodaj extends Wyrazenie
{
    Wyrazenie left, right;

    public Dodaj(Wyrazenie a, Wyrazenie b)
    {
        left=a;
        right=b;
    }

    public int oblicz()
    {
        return left.oblicz() + right.oblicz();
    }

    public String ToString()
    {
        return "(" + left.ToString() + "+" + right.ToString() + ")";
    }

}

class Odejmij extends Wyrazenie
{
    Wyrazenie left, right;

    public Odejmij(Wyrazenie a, Wyrazenie b)
    {
        left=a;
        right=b;
    }

    public int oblicz()
    {
        return left.oblicz() - right.oblicz();
    }

    public String ToString()
    {
        return "(" + left.ToString() + "-" + right.ToString() + ")";
    }

}

class Mnozenie extends Wyrazenie
{
    Wyrazenie left, right;

    public Mnozenie(Wyrazenie a, Wyrazenie b)
    {
        left=a;
        right=b;
    }

    public int oblicz()
    {
        return left.oblicz() * right.oblicz();
    }

    public String ToString()
    {
        return "(" + left.ToString() + "*" + right.ToString() + ")";
    }

}

class Dzielenie extends Wyrazenie
{
    Wyrazenie left, right;

    public Dzielenie(Wyrazenie a, Wyrazenie b)
    {
        left=a;
        right=b;
    }

    public int oblicz()
    {
        return left.oblicz() / right.oblicz();
    }

    public String ToString()
    {
        return "(" + left.ToString() + "/" + right.ToString() + ")";
    }
}

class Potegowanie extends Wyrazenie
{
    Wyrazenie left, right;

    public Potegowanie(Wyrazenie a, Wyrazenie b)
    {
        left=a;
        right=b;
    }

    public int oblicz()
    {
        return (int)Math.pow(left.oblicz(), right.oblicz());
    }

    public String ToString()
    {
        return "(" + left.ToString() + "^" + right.ToString() + ")";
    }
}

class Modulo extends Wyrazenie
{
    Wyrazenie left, right;

    public Modulo(Wyrazenie a, Wyrazenie b)
    {
        left=a;
        right=b;
    }

    public int oblicz()
    {
        return left.oblicz() % right.oblicz();
    }

    public String ToString()
    {
        return "(" + left.ToString() + "%" + right.ToString() + ")";
    }
}
