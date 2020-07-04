#include <iostream>
#include "Zadanie1.hpp"

wektor::wektor(double x, double y)
{
    dx=x;
    dy=y;
}

wektor::wektor(const wektor &kopia_wektora)
{
    dx=kopia_wektora.dx;
    dy=kopia_wektora.dy;
}

punkt::punkt(const double wspx, const double wspy)
{
    x=wspx;
    y=wspy;
}

punkt::punkt(const punkt &inny_punkt, const wektor &przesuniecie)
{
    x=inny_punkt.x+przesuniecie.dx;
    y=inny_punkt.y+przesuniecie.dy;
}

punkt::punkt(const punkt &kopia_punktu)
{
    x=kopia_punktu.x;
    y=kopia_punktu.y;
}

double prosta::get_A() const
{
    return A;
}
double prosta::get_B() const
{
    return B;
}
double prosta::get_C() const
{
    return C;
}

prosta::prosta(const punkt &punkt1, const punkt &punkt2)
{
    if(punkt1.x==punkt2.x && punkt1.y==punkt2.y)
    {
        throw std::invalid_argument("To sa te same punkty! Nie mozna utworzyc prostej!\n");
    }
    A=punkt2.y-punkt1.y;
    B=punkt1.x-punkt2.x;
    C=punkt2.x*punkt1.y-punkt1.x*punkt2.y;
}

prosta::prosta(const wektor &wektor1)
{
    prosta pom(punkt(0,0),punkt(punkt(0,0),wektor1));
    A=pom.B*(-1);
    B=pom.A;
    C=(wektor1.dy*B+A*wektor1.dx);
}

prosta::prosta(const double wspA, const double wspB, const double wspC)
{
    if(wspA!=0 || wspB!=0)
    {
        A=wspA;
        B=wspB;
    }
    else
    {
        throw std::invalid_argument("Wspolczynnik A i B rowny zero!\n");
    }

    C=wspC;
}

prosta::prosta(const prosta &stara, const wektor &wektor1)
{
    A=stara.A/stara.B;
    B=1;
    C=(stara.A*wektor1.dx)/stara.B+wektor1.dy+stara.C;
}


wektor Zlozenie_wektora(wektor Wektor1, wektor Wektor2)
{
    wektor Nowy(Wektor1.dx+Wektor2.dx,Wektor1.dy+Wektor2.dy);

    return Nowy;
}

bool Czy_prostopadle(prosta Prosta1, prosta Prosta2)
{

    if(Prosta1.get_A()*Prosta2.get_A()==-1)
        return true;

    return false;
}

bool Czy_rownolegle(prosta Prosta1, prosta Prosta2)
{

    if(Prosta1.get_A()==Prosta2.get_A())
        return true;

    return false;
}

bool prosta::Czy_wektor_prostopadly(wektor Wektor1, prosta Prosta1)
{
    if(Wektor1.dx==Prosta1.get_A() && Wektor1.dy==Prosta1.get_B())
        return true;

    return false;
}

bool prosta::Czy_wektor_rownolegly(wektor Wektor1, prosta Prosta1)
{
    if(Wektor1.dx==1 && Wektor1.dy==(-1)*Prosta1.get_B())
        return true;

    return false;
}

bool prosta::Czy_lezy_na_prostej(punkt Punkt1, prosta Prosta1)
{
    if(Prosta1.get_A()*Punkt1.x+Prosta1.get_B()*Punkt1.y+Prosta1.get_C()==0)
        return true;

    return false;
}

void Punkt_przeciecia(prosta Prosta1, prosta Prosta2)
{
    double x, y;

    if(Prosta1.get_A()*Prosta2.get_B()!=Prosta1.get_B()*Prosta2.get_A())
    {
        x=(Prosta2.get_C()*Prosta1.get_B()-Prosta1.get_C()*Prosta2.get_B())/(Prosta1.get_A()*Prosta2.get_B()!=Prosta1.get_B()*Prosta2.get_A());
        y=Prosta1.get_A()*x+Prosta1.get_C();
        std::cout<<"("<<x<<", "<<y<<")\n";
    }
    else
    {
        std::cout<<"Te proste sa rownolegle!\n";
    }
}

