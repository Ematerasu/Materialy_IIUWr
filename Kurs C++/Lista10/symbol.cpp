#include "symbol.hpp"
#include "operand.hpp"
#include <iostream>
#include <stack>

using namespace kalkulator;

double symbol::result()
{
	if (symbol::stos.size() != 1)
		std::clog<<"Niepoprawne dzialanie";

	double wynik = static_cast<liczba*>(symbol::stos.top())->get_wartosc();
	stos.pop();
	return wynik;
}