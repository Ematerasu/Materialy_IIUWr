	#include<iostream>
#include "tabbit.hpp"

void tab_bit::ref::SetBit(slowo *tb, int index, bool wartosc)
{
	tb[index] = wartosc;
}

bool tab_bit::ref::GetBit(slowo *tb, int index)
{
	return tb[index];
}

tab_bit::tab_bit(int rozm)
{
	if (rozm > 0)
	{
		dl = rozm;
		tab = new slowo[dl];
		for (int i = 0; i < dl; i++) tab[i] = 0;
	}
	else
		throw std::invalid_argument("Rozmiar musi byc przynajmniej rowny 1");
	
}
tab_bit::tab_bit(slowo wzorzec)
{
	dl = sizeof(slowo) * sizeof(wzorzec);
	tab = new slowo[dl];
	for (int i = 0; i < dl; i++) tab[i] = 0;
}

tab_bit::tab_bit(const tab_bit& tb)
{
	dl = tb.dl;
	tab = nullptr;
	tab = new slowo[dl];
	for (int i = 0; i < dl; i++) tab[i] = tb.tab[i];
}
tab_bit::tab_bit(tab_bit&& tb)
{
	dl = tb.dl;
	tab = nullptr;
	tab = new slowo[dl];
	for (int i = 0; i < dl; i++) tab[i] = tb.tab[i];
	tb.dl = 0;
	tb.tab = nullptr;
}
tab_bit::~tab_bit()
{
	if (tab)
	{
		delete[] tab;
	}
	
}
bool tab_bit::czytaj(int i) const
{
	tab_bit::ref obj;
	return obj.GetBit(tab, i);
}

bool tab_bit::pisz(int i, bool b)
{
	tab_bit::ref obj;
	obj.SetBit(tab, i, b);
	return true;
}

tab_bit& tab_bit::operator=(const tab_bit& obj)
{
	dl = obj.dl;
	tab = nullptr;
	tab = new slowo[dl];
	for (int i = 0; i < dl; ++i) tab[i] = obj.tab[i];
	return *this;
}

tab_bit& tab_bit::operator=(tab_bit&& obj)
{
	dl = obj.dl;
	tab = obj.tab;
	obj.dl = 0;
	obj.tab = nullptr;
	return *this;
}

int tab_bit::rozmiar() const
{
	return dl;
}
