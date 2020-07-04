#ifndef TABBIT_HPP_INCLUDED
#define TABBIT_HPP_INCLUDED
#include <iostream>
#include <ostream>
#include <cmath>
#include <initializer_list>

class tab_bit
{
	typedef uint64_t slowo; // komorka w tablicy
	static const int rozmiarSlowa; // rozmiar slowa w bitach
	friend std::istream& operator >> (std::istream& we, tab_bit& tb);
	friend std::ostream& operator << (std::ostream& wy, const tab_bit& tb);
	class ref 
	{
	public:
		void SetBit(slowo *tb, int index, bool wartosc);
		bool GetBit(slowo *tb, int index);
	}; // klasa pomocnicza do adresowania bitów
protected:
	int dl; // liczba bitów
	slowo* tab; // tablica bitów
public:
	explicit tab_bit(int rozm);
	explicit tab_bit(slowo wzorzec);
	tab_bit(const tab_bit& tb); // konstruktor kopiuj¹cy
	tab_bit(tab_bit&& tb); // konstruktor przenosz¹cy
	tab_bit& operator = (const tab_bit& tb); // przypisanie kopiuj¹ce
	tab_bit& operator = (tab_bit&& tb); // przypisanie przenosz¹ce
	~tab_bit(); // destruktor
private:
	bool czytaj(int i) const; // metoda pomocnicza do odczytu bitu
	bool pisz(int i, bool b); // metoda pomocnicza do zapisu bitu
public:
	bool operator[] (int i) const; // indeksowanie dla sta³ych tablic bitowych
	ref operator[] (int i); // indeksowanie dla zwyk³ych tablic bitowych
	int rozmiar() const; // rozmiar tablicy w bitach
public:
	friend tab_bit operator | (const tab_bit& f, const tab_bit& g);
	friend tab_bit operator & (const tab_bit& f, const tab_bit& g);
	friend tab_bit operator ^ (const tab_bit& f, const tab_bit& g);
public:
	tab_bit& operator |= (const tab_bit& f);
	tab_bit& operator &= (const tab_bit& f);
	tab_bit& operator ^= (const tab_bit& f);
	tab_bit operator ! ();
};



#endif // TABBIT_HPP_INCLUDED
