#include "wymierne.hpp"

using namespace obliczenia;

wymierna::wymierna(int a, int b)
{
    if(b == 0)
    {
        throw DzieleniePrzezZero("Nie dziel przez zero");
    }
    else if(b > 0)
    {
        licz = a;
        mian = b;
    }
    else if(b < 0)
    {
        licz = a * -1;
        mian = b * -1;
    }
    Skroc();
}

wymierna::wymierna(int a)
{
    licz = a;
    mian = 1;
}

void wymierna::Skroc()
{
    int a= licz >0 ? licz : licz * -1;
    int b = mian;
    while(a!=b)
    {
    if(a>b)
        a-=b;
    else
        b-=a;
    }
    this->licz = licz / a;
    this->mian = mian /a;
}

namespace obliczenia
{
    int rozwiniecie(int a) //ulamek ma rozwiniecie skonczone gdy jego mianownik rozklada sie tylko na 2 i 5
    {
        int w = 0;
        while (a % 2 == 0)
        {
            a /= 2;
            w++;
        }
        while (a % 5 == 0)
        {
            a /= 5;
            w++;
        }
        return w;
    }

    ostream& operator << (ostream & wyj, const wymierna & w)
    {
        if (w.get_licz() / w.get_mian() == 0 && w.get_licz() < 0)
            wyj << "-";
        wyj << w.get_licz() / w.get_mian();
        if (w.get_licz() % w.get_mian() != 0)
        {
            wyj << ",";
            int o = w.get_licz() % w.get_mian();
            o *= 10;
            for (int i = 0; i < rozwiniecie(w.get_mian()); i++) //rozwiniecie dziesietne
            {
                wyj << abs(o / w.get_mian());
                o %= w.get_mian();
                o *= 10;
            }
   
            if (o != 0) //okres
            {
                int p = o;
                int i = 1; //zeby nie powtarzac tej samej liczby
                wyj << "(";
                while (p != o || i == 1)
                {
                    wyj << abs(o / w.get_mian());
                    o %= w.get_mian();
                    o *= 10;
                    i++;
                }
                wyj << ")";
            }
        }
        return wyj;
    }
}

wymierna & wymierna::operator + (const wymierna &w1)
{
    int l, m;
    l = this->licz*w1.get_mian() + w1.get_licz() * this->mian;
    m = this->mian * w1.get_mian();
    if (l > INT_MAX || m > INT_MAX)
    {
        throw PrzekroczenieZakresu("Przekroczono zakres");
        wymierna* temp = new wymierna(this->licz, this->mian);
        return *temp;
    }
    else
    {
        wymierna* temp = new wymierna(l, m);
        return *temp;
    }
    
}

wymierna& wymierna::operator - (const wymierna& w1)
{
    int l, m;
    l = this->licz * w1.get_mian() - w1.get_licz() * this->mian;
    m = this->mian * w1.get_mian();
    if (l > INT_MAX || m > INT_MAX)
    {
        throw PrzekroczenieZakresu("Przekroczono zakres");
        wymierna* temp = new wymierna(this->licz, this->mian);
        return *temp;
    }
    else
    {
        wymierna* temp = new wymierna(l, m);
        return *temp;
    }
}

wymierna & wymierna::operator * (const wymierna &w1)
{
    int l, m;
    l = this->licz * w1.get_licz();
    m = this->mian * w1.get_mian();
    if (l > INT_MAX || m > INT_MAX)
    {
        throw PrzekroczenieZakresu("Przekroczono zakres");
        wymierna* temp = new wymierna(this->licz, this->mian);
        return *temp;
    }
    else
    {
        wymierna* temp = new wymierna(l, m);
        return *temp;
    }
}

wymierna& wymierna::operator / (const wymierna& w1)
{
    int l, m;
    if (w1.get_licz() == 0)
        throw DzieleniePrzezZero("Nie dziel przez zero");
    l = this->licz * w1.get_mian();
    m = this->mian * w1.get_licz();
    if (l > INT_MAX || m > INT_MAX)
    {
        throw PrzekroczenieZakresu("Przekroczono zakres");
        wymierna* temp = new wymierna(this->licz, this->mian);
        return *temp;
    }
    else
    {
        wymierna* temp = new wymierna(l, m);
        return *temp;
    }
}

wymierna & wymierna::operator ! ()
{
    int l, m;
    l = this->licz;
    m = this->mian;
    if (l == 0)
        throw DzieleniePrzezZero("Nie dziel przez zero");
    if (l < 0)
    {
        int temp = l * -1;
        l = m * -1;
        m = temp;
    }
    else
    {
        int temp = l;
        l = m;
        m = temp;
    }
    if (l > INT_MAX || l > INT_MAX)
    {
        throw PrzekroczenieZakresu("Przekroczono zakres");
        wymierna* temp = new wymierna(1);
        return *temp;
    }
    wymierna* temp = new wymierna(l,m);
    return *temp;
}

wymierna & wymierna::operator - ()
{
    int l, m;
    l = this->licz;
    m = this->mian;

    l = l * -1;
    wymierna* temp = new wymierna(l, m);
    return *temp;
}

wymierna::operator double()
{
    return (double)this->licz / this->mian;
}

wymierna::operator int()
{
    return this->licz / this->mian;
}



DzieleniePrzezZero::DzieleniePrzezZero(const char* t)
{
    tresc_bledu = t;
}

const char* DzieleniePrzezZero::what()
{
    return tresc_bledu.c_str();
}

PrzekroczenieZakresu::PrzekroczenieZakresu(const char* t)
{
    tresc_bledu = t;
}

const char* PrzekroczenieZakresu::what()
{
    return tresc_bledu.c_str();
}
