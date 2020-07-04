#include "lista.hpp"

using namespace std;

int main()
{

    lista<int>* test1 = new lista<int>();

    test1->wstaw(5, 1);
    test1->wstaw(3, 2);
    test1->wstaw(7, 3);
    
    cout <<"Ilosc elementow na liscie: " << test1->ilosc() << endl;
    cout << test1->znajdz(5) << endl;
    cout << test1->znajdz(7) << endl;
    test1->usun(5);
    cout << "Ilosc elementow na liscie: " << test1->ilosc() << endl;
    cout << test1->znajdz(7) << endl;
    delete test1;
    return 0;
}