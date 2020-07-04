#ifndef STOS_HPP_INCLUDED
#define STOS_HPP_INCLUDED
#include <iostream>
#include <initializer_list>

using namespace std;

class Stos
{
private:
	int pojemnosc;
	int ile=0;
public:
	int get_ile() const
	{
		return ile;
	}
	int get_poj() const
	{
		return pojemnosc;
	}
	void set_ile(int x)
	{
		ile = x;
	}
	void set_poj(int x)
	{
		pojemnosc = x;
	}

	string* stos;

	Stos();
	Stos(const int poj);
	Stos(const Stos& stos);
	Stos(const Stos && orig);
	Stos(initializer_list<string> list);
	~Stos();

	Stos & operator =(const Stos &);
	Stos & operator =(Stos && orig);

	void wloz(string slowo);
	string sciagnij();
	string sprawdz();
	int rozmiar();
	Stos *Odwroc();

};

#endif // STOS_HPP_INCLUDED
