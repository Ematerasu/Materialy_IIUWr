#ifndef WYMIERNE_HPP_INCLUDED
#define WYMIERNE_HPP_INCLUDED
#include <iostream>

using namespace std ;

namespace obliczenia
{
    class wymierna
    {
    private:
        int licz, mian;
        void Skroc();
    
    public:
        int get_licz() const {return licz;};
        int get_mian() const {return mian;};
        wymierna(int a, int b);
        wymierna(int a);
        wymierna(const wymierna &) = default;
        wymierna & operator = (const wymierna &) = default;
    
        wymierna & operator + (const wymierna &);
        wymierna & operator - (const wymierna &);
        wymierna & operator * (const wymierna &);
        wymierna & operator / (const wymierna &);
        wymierna & operator ! ();
        wymierna & operator - ();

        operator double();
        explicit operator int();

        friend ostream& operator<< (ostream& wyj, const wymierna& w);

};
}

class wyjatek_wymierny : public exception
{
protected:
    string tresc_bledu;
public:
    wyjatek_wymierny() = default;
};

class DzieleniePrzezZero : public wyjatek_wymierny
{
public:
    DzieleniePrzezZero() = default;
    DzieleniePrzezZero(const char* t);
    DzieleniePrzezZero(const DzieleniePrzezZero& c) = default;
    DzieleniePrzezZero& operator = (const DzieleniePrzezZero& tb) = default;
    virtual const char* what();
    virtual ~DzieleniePrzezZero() = default;
};

class PrzekroczenieZakresu : public wyjatek_wymierny
{
public:
    PrzekroczenieZakresu() = default;
    PrzekroczenieZakresu(const char* t);
    PrzekroczenieZakresu(const PrzekroczenieZakresu& c) = default;
    PrzekroczenieZakresu& operator = (const PrzekroczenieZakresu& tb) = default;
    virtual const char* what();
    virtual ~PrzekroczenieZakresu() = default;
};


#endif