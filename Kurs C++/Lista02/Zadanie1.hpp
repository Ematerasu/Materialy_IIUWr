#ifndef ZADANIE1_HPP_INCLUDED
#define ZADANIE1_HPP_INCLUDED
#include <iostream>

class wektor
{

public:
    double dx, dy;
    wektor()=default;
    wektor(double x, double y);
    wektor(const wektor &kopia_wektora);

};

class punkt
{

public:
    double x, y;
    punkt()=default;
    punkt(const double wspx, const double wspy);
    punkt(const punkt &inny_punkt, const wektor &przesuniecie);
    punkt(const punkt &kopia_punktu);

};

class prosta
{

private:
    double A, B, C;

public:
    double get_A() const;
    double get_B() const;
    double get_C() const;

    prosta()=default;
    prosta(const punkt &punkt1, const punkt &punkt2);
    prosta(const wektor &wektor1);
    prosta(const double wspA, const double wspB, const double wspC);
    prosta(const prosta &stara, const wektor &wektor1);
    bool Czy_wektor_prostopadly(wektor Wektor1, prosta Prosta1);
    bool Czy_wektor_rownolegly(wektor Wektor1, prosta Prosta1);
    bool Czy_lezy_na_prostej(punkt Punkt1, prosta Prosta1);

};


wektor Zlozenie_wektora(wektor Wektor1, wektor Wektor2);
bool Czy_prostopadle(prosta Prosta1, prosta Prosta2);
bool Czy_rownolegle(prosta Prosta1, prosta Prosta2);

void Punkt_przeciecia(prosta Prosta1, prosta Prosta2);

#endif // ZADANIE1_HPP_INCLUDED
