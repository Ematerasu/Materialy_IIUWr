#ifndef WYRAZENIE_H_INCLUDED
#define WYRAZENIE_H_INCLUDED
class Wyrazenie {
public:
    virtual double oblicz();
    virtual std::string opis();
};

class Dodaj : public Wyrazenie
{
public:
    Wyrazenie* left, * right;

        Dodaj(Wyrazenie* a, Wyrazenie* b);
        virtual double oblicz();
        virtual std::string opis();
};

class Odejmij : public Wyrazenie
{
public:
    Wyrazenie* left, * right;

    Odejmij(Wyrazenie* a, Wyrazenie* b);
    virtual double oblicz();
    virtual std::string opis();
};

class Mnozenie : public Wyrazenie
{
public:
    Wyrazenie* left, * right;

    Mnozenie(Wyrazenie* a, Wyrazenie* b)
    {
        left = a;
        right = b;
    }

    double oblicz()
    {
        return left->oblicz() * right->oblicz();
    }

    std::string opis()
    {
        return "(" + left->opis() + "*" + right->opis() + ")";
    }

};

class Dzielenie : public Wyrazenie
{
public:
    Wyrazenie* left, * right;

    Dzielenie(Wyrazenie* a, Wyrazenie* b)
    {
        left = a;
        right = b;
    }

    double oblicz()
    {
        return left->oblicz() / right->oblicz();
    }

    std::string opis()
    {
        return "(" + left->opis() + "/" + right->opis() + ")";
    }

};

class Potega : public Wyrazenie
{
public:
    Wyrazenie* left, * right;

    Potega(Wyrazenie* a, Wyrazenie* b)
    {
        left = a;
        right = b;
    }

    double oblicz()
    {
        return pow(left->oblicz(), right->oblicz());
    }

    std::string opis()
    {
        return "(" + left->opis() + "^" + right->opis() + ")";
    }

};

class Modulo : public Wyrazenie
{
public:
    Wyrazenie* left, * right;

    Modulo(Wyrazenie* a, Wyrazenie* b)
    {
        left = a;
        right = b;
    }

    double oblicz()
    {
        return fmod(left->oblicz(), right->oblicz());
    }

    std::string opis()
    {
        return "(" + left->opis() + "%" + right->opis() + ")";
    }

};

class Logarytm : public Wyrazenie
{
public:
    Wyrazenie left, right; //left-podstawa

    Logarytm(Wyrazenie a, Wyrazenie b)
    {
        left = a;
        right = b;
    }

    double oblicz()
    {
        return (log(right.oblicz()) / log(left.oblicz()));
    }

    std::string opis()
    {
        return "(log(" + left.opis() + ")" + right.opis() + ")";
    }

};

class Zmienna : public Wyrazenie
{
public:
    std::string nazwa_zmiennej;
    std::vector<std::pair<std::string, double>> wartosci_zmiennych;

    Zmienna(std::string nazwa_zmiennej, double wartosc_zmiennej)
    {
        this->nazwa_zmiennej = nazwa_zmiennej;
        wartosci_zmiennych.push_back(std::make_pair(nazwa_zmiennej, wartosc_zmiennej));
    }

    double oblicz()
    {
        for (unsigned int i = 0; i < wartosci_zmiennych.size(); i++)
        {
            if (nazwa_zmiennej == wartosci_zmiennych[i].first)
            {
                return wartosci_zmiennych[i].second;
            }
        }
    }

    std::string opis()
    {
        return this->nazwa_zmiennej;
    }
};

class liczba : public Wyrazenie
{
public:
    double Wartosc;

    liczba(double val)
    {
        Wartosc = val;
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return std::to_string(Wartosc);
    }

};

class stala : public Wyrazenie
{
public:
    double Wartosc;
    std::string nazwa;

    stala(std::string nazwa, double val)
    {
        Wartosc = val;
        this->nazwa = nazwa;
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return nazwa;
    }

};



class sin : public Wyrazenie
{
public:
    Wyrazenie arg;

    sin(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return std::sin(arg.oblicz());
    }

    std::string opis()
    {
        return "sin(" + arg.opis() + ")";
    }

};

class cos : public Wyrazenie
{
public:
    Wyrazenie arg;

    cos(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return std::cos(arg.oblicz());
    }

    std::string opis()
    {
        return "cos(" + arg.opis() + ")";
    }

};

class ln : public Wyrazenie
{
public:
    Wyrazenie arg;

    ln(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return log(arg.oblicz());
    }

    std::string opis()
    {
        return "ln(" + arg.opis() + ")";
    }

};

class exp : public Wyrazenie
{
public:
    Wyrazenie arg;

    exp(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return std::exp(arg.oblicz());
    }

    std::string opis()
    {
        return "exp(" + arg.opis() + ")";
    }

};

class bezwzgl : public Wyrazenie
{
public:
    Wyrazenie arg;

    bezwzgl(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return abs(arg.oblicz());
    }

    std::string opis()
    {
        return "(|" + arg.opis() + "|)";
    }

};

class przeciw : public Wyrazenie
{
public:
    Wyrazenie arg;

    przeciw(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return arg.oblicz() * (-1);
    }

    std::string opis()
    {
        return "przeciw(" + arg.opis() + ")";
    }

};

class odwrot : public Wyrazenie
{
public:
    Wyrazenie arg;

    odwrot(Wyrazenie a)
    {
        arg = a;
    }

    double oblicz()
    {
        return 1 / arg.oblicz();
    }

    std::string opis()
    {
        return "(1/" + arg.opis() + ")";
    }

};

class pi : public Wyrazenie
{
public:
    double Wartosc;

    pi()
    {
        Wartosc = 3.141592;
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return std::to_string(Wartosc);
    }

};

class e : public Wyrazenie
{
public:
    double Wartosc;

    e()
    {
        Wartosc = 2.718281828;
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return std::to_string(Wartosc);
    }

};

class fi : public Wyrazenie
{
public:
    double Wartosc;

    fi()
    {
        Wartosc = 1.61803;
    }

    double oblicz()
    {
        return Wartosc;
    }

    std::string opis()
    {
        return std::to_string(Wartosc);
    }

};


#endif // WYRAZENIE_H_INCLUDED
