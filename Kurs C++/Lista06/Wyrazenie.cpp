#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>


class Wyrazenie {
public:
    virtual double oblicz() = 0;
    virtual std::string opis() = 0;
    ~Wyrazenie() = default;
    virtual int get_prio() = 0;
};

class operator1arg : public Wyrazenie
{
public:
    Wyrazenie* arg;
    ~operator1arg() = default;
};

class operator2arg : public operator1arg
{
public:
    Wyrazenie* arg2;
    ~operator2arg() = default;
};

class Dodaj : public operator2arg
{
private:
    int priorytet = 1;
public:
   
    Dodaj(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    virtual double oblicz()
    {
        return arg->oblicz() + arg2->oblicz();
    }

    virtual std::string opis()
    {
        return arg->opis() + "+" + arg2->opis();
    }
    virtual int get_prio() { return priorytet; };


};

class Odejmij : public operator2arg
{
private:
    int priorytet = 1;

public:

    Odejmij(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    virtual double oblicz()
    {
        return arg->oblicz() - arg2->oblicz();
    }

    virtual std::string opis()
    {
        if (arg2->get_prio() == this->get_prio())
        {
            return arg->opis() + "- (" + arg2->opis() + ")";
        }
        return arg->opis() + "-" + arg2->opis();
    }
    virtual int get_prio() { return priorytet; };
};

class Mnozenie : public operator2arg
{
private:
    int priorytet = 2;
public:
    Mnozenie(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    virtual double oblicz()
    {
        return arg->oblicz() * arg2->oblicz();
    }

    virtual std::string opis()
    {
        std::string left = arg->opis();
        if (arg->get_prio() < priorytet)
            left = "(" + left + ")";
        std::string right = arg2->opis();
        if (arg2->get_prio() < priorytet)
            right = "(" + right + ")";
        return left + " * " + right;
    }
    virtual int get_prio() { return priorytet; };
};

class Dzielenie : public operator2arg
{
private:
    int priorytet = 2;
public:
    Dzielenie(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    virtual double oblicz()
    {
        if (arg2->oblicz() != 0) return arg->oblicz() / arg2->oblicz();
        else
        {
            throw "Dzielenie przez zero, blad!";
            return arg->oblicz();
        }
    }

    virtual std::string opis()
    {
        std::string left = arg->opis();
        if (arg->get_prio() < priorytet)
            left = "(" + left + ")";
        std::string right = arg2->opis();
        if (arg2->get_prio() <= priorytet)
            right = "(" + right + ")";
        return left + " / " + right;
    }
    virtual int get_prio() { return priorytet; };
};

class Potega : public operator2arg
{
private:
    int priorytet = 3;
public:
    Potega(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    virtual double oblicz()
    {
        return pow(arg->oblicz(), arg2->oblicz());
    }

    virtual std::string opis()
    {
        std::string left = arg->opis();
        if (arg->get_prio() < priorytet)
            left = "(" + left + ")";
        std::string right = arg2->opis();
        if (arg2->get_prio() < priorytet)
            right = "(" + right + ")";
        return left + " ^ " + right;
    }
    virtual int get_prio() { return priorytet; };
};

class Modulo : public operator2arg
{
private:
    int priorytet = 2;
public:
    Modulo(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    virtual double oblicz()
    {
        return fmod(arg->oblicz(), arg2->oblicz());
    }

    virtual std::string opis()
    {
        std::string left = arg->opis();
        if (arg->get_prio() < priorytet)
            left = "(" + left + ")";
        std::string right = arg2->opis();
        if (arg2->get_prio() < priorytet)
            right = "(" + right + ")";
        return left + " % " + right;
    }
    virtual int get_prio() { return priorytet; };
};

class Logarytm : public operator2arg
{
private:
    int priorytet = 3;
public:

    Logarytm(Wyrazenie *a, Wyrazenie *b)
    {
        arg = a;
        arg2 = b;
    }

    double oblicz()
    {
        return (log(arg2->oblicz()) / log(arg->oblicz()));
    }

    std::string opis()
    {
        std::string left = arg->opis();
        if (arg->get_prio() <= priorytet)
            left = "(" + left + ")";
        std::string right = arg2->opis();
        if (arg2->get_prio() <= priorytet)
            right = "(" + right + ")";
        return "log(" + left + " ) " + right;
    }
    virtual int get_prio() { return priorytet; };
};

class Zmienna : public Wyrazenie
{
private:
    int priorytet = 5;
    std::string nazwa_zmiennej;
    std::vector<std::pair<std::string, double>> wartosci_zmiennych;

public:

    Zmienna(std::string nazwa_zmiennej, double wartosc_zmiennej)
    {
        this->nazwa_zmiennej = nazwa_zmiennej;
        wartosci_zmiennych.push_back(std::make_pair(nazwa_zmiennej, wartosc_zmiennej));
    }

    Zmienna(std::string nazwa_zmiennej)
    {
        this->nazwa_zmiennej = nazwa_zmiennej;
    }

    void AddValue(std::string nazwa, double val)
    {
        if (!IsThere(nazwa))
            wartosci_zmiennych.push_back(std::make_pair(nazwa, val));
        else
        {
            for (auto i = wartosci_zmiennych.begin(); i != wartosci_zmiennych.end(); i++)
            {
                if (i->first == nazwa)
                    i->second = val;
            }
        }
    }

    bool IsThere(std::string nazwa)
    {
        for (auto i = wartosci_zmiennych.begin(); i != wartosci_zmiennych.end(); i++)
        {
            if (i->first == nazwa)
                return true;
        }
        return false;
    }

    double oblicz()
    {
        if (IsThere(nazwa_zmiennej))
        {
            for (auto i = wartosci_zmiennych.begin(); i != wartosci_zmiennych.end(); i++)
            {
                if (i->first == nazwa_zmiennej)
                    return i->second;
            }
        }

        throw "Brak wartosci zmiennej";
    }

    std::string opis()
    {
        return nazwa_zmiennej;
    }

    virtual int get_prio() { return priorytet; };
};

class liczba : public Wyrazenie
{
private:
    int priorytet = 5;
public:
    double Wartosc;

    liczba(double val)
    {
        Wartosc = val;
    }

    virtual double oblicz()
    {
        return Wartosc;
    }

    virtual std::string opis()
    {
        return std::to_string(Wartosc);
    }
    virtual int get_prio() { return priorytet; };
};

class stala : public Wyrazenie
{
private:
    int priorytet = 5;
public:
    double Wartosc;
    std::string nazwa;

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return nazwa;
    }
    virtual int get_prio() { return priorytet; };
};



class Sin : public operator1arg
{
private:
    int priorytet = 4;
public:
    Sin(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        return sin(arg->oblicz());
    }

    std::string opis()
    {
        return "sin("+arg->opis()+")";
    }
    virtual int get_prio() { return priorytet; };
};

class Cos : public operator1arg
{
private:
    int priorytet = 4;
public:
    Cos(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        return cos(arg->oblicz());
    }

    std::string opis()
    {
        return "cos(" + arg->opis() + ")";
    }
    virtual int get_prio() { return priorytet; };
};

class ln : public operator1arg
{
private:
    int priorytet = 3;
public:
    ln(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        return log(arg->oblicz());
    }

    std::string opis()
    {
        return "ln(" + arg->opis() + ")";
    }
    virtual int get_prio() { return priorytet; };
};

class Exp : public operator1arg
{
private:
    int priorytet = 4;
public:
    Exp(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        return exp(arg->oblicz());
    }

    std::string opis()
    {
        return "exp(" + arg->opis() + ")";
    }
    virtual int get_prio() { return priorytet; };
};

class bezwzgl : public operator1arg
{
private:
    int priorytet = 4;
public:
    bezwzgl(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        return abs(arg->oblicz());
    }

    std::string opis()
    {
        return "|" + arg->opis() + "|";
    }
    virtual int get_prio() { return priorytet; };
};

class przeciw : public operator1arg
{
private:
    int priorytet = 4;
public:
    przeciw(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        return arg->oblicz() * (-1);
    }

    std::string opis()
    {
        return "przeciw(" + arg->opis() + ")";
    }
    virtual int get_prio() { return priorytet; };
};

class odwrot : public operator1arg
{
private:
    int priorytet = 4;
public:

    odwrot(Wyrazenie *a)
    {
        arg = a;
    }

    double oblicz()
    {
        if (arg->oblicz() != 0) return 1 / arg->oblicz();
        else return 0;
    }

    std::string opis()
    {
        return "(1/" + arg->opis() + ")";
    }
    virtual int get_prio() { return priorytet; };
};

class pi : public stala
{
private:
    int priorytet = 5;
public:
    pi()
    {
        Wartosc = 3.141592;
        nazwa = "pi";
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return nazwa;
    }
    virtual int get_prio() { return priorytet; };
};

class e : public stala
{
private:
    int priorytet = 5;
public:
    e()
    {
        Wartosc = 2.718281828;
        nazwa = "e";
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return nazwa;
    }
    virtual int get_prio() { return priorytet; };
};

class fi : public stala
{
private:
    int priorytet = 5;
public:
    fi()
    {
        Wartosc = 1.61803;
        nazwa = "fi";
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return nazwa;
    }
    virtual int get_prio() { return priorytet; };
};