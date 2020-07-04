//Nie udalo mi sie wykonac calego zadania,
//Stworzylem konstruktory, destruktor i operatory do kopiowania i przypisania,
//do tego jeszcze pare metod, ale nie zrozumialem za bardzo zadania.

#include <iostream>
#include "tabbit.hpp"

using namespace std;

int main()
{
    tab_bit test = tab_bit(2);
    tab_bit test2 = tab_bit(test);
    std::cout << test2.rozmiar();
    return 0;
}
