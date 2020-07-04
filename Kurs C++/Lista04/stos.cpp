#include <iostream>
#include "stos.hpp"

Stos::Stos() : Stos(1) {}

Stos::Stos(const int poj)
{
    this->stos = new string[poj];
    set_poj(poj);
}

Stos::Stos(const Stos &orig)
{ 
    this->ile = orig.get_ile();;
    this->pojemnosc = orig.get_poj();
    this->stos = new string[orig.get_poj()];
    copy(orig.stos, orig.stos + ile, this->stos);
}

Stos::Stos(const Stos && orig)
{
    this->ile = orig.get_ile();
    this->pojemnosc = orig.get_poj();
    this->stos = new string[orig.get_poj()];
    copy(orig.stos, orig.stos + ile, this->stos);
    delete [] orig.stos;
}

Stos::Stos(initializer_list<std::string> list)
{
    this->ile = list.size();
    this-> pojemnosc = list.size();
    this->stos = new string[list.size()];

    for(const std::string& x : list)
    {
        wloz(x);
    }
}

Stos::~Stos()
{
    delete[] &stos;
}

Stos & Stos::operator =(const Stos & orig)
{
    if (this != &orig)
    {
        delete[] this->stos;

        this->stos = new string[orig.get_poj()];
        int ile = orig.get_ile();
        this->ile = ile;
        this->pojemnosc = orig.get_poj();
        copy(orig.stos, orig.stos + ile, this->stos);

    }
    return *this;
}

Stos & Stos::operator =(Stos && orig)
{
    if (this != &orig)
    {
        delete[] this->stos;
        this->ile =orig.get_ile();
        this->pojemnosc = orig.get_poj();
        this->stos = orig.stos;
        orig.stos = nullptr;

    }
    return *this;
}

void Stos::wloz(std::string slowo)
{
    if (this->ile >= this->pojemnosc)
    {
        std::cout << "Stos jest pelny!\n";
        return;
    }
    this->stos[this->ile] = slowo;
    this->ile++;
}

string Stos::sciagnij()
{
    if (rozmiar() > 0)
    {
        this->ile -= 1;
        string result = stos[this->ile];
        return result;
    }
    else return "Pusty stos\n";
    
}

string Stos::sprawdz()
{
    int ile = get_ile();
    if (ile > 0) return stos[ile - 1];
    else return "Stos jest pusty!\n";
}

int Stos::rozmiar()
{
    return get_ile();
}

Stos *Stos::Odwroc()
{
    Stos *nowy = new Stos(this->get_poj());

    for (int i = 0; i < this->ile; i++)
    {
        nowy->wloz(this->stos[this->ile - 1 - i]);
    }
    return nowy;
}


