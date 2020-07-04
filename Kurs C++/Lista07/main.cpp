#include <iostream>
#include "wymierne.hpp"

using namespace obliczenia;

int main()
{
    try
    {
        wymierna test(1, 2);
        wymierna test2(3, 4);
        cout << test << endl;
        cout << test2 << endl;
        wymierna test3 = test + test2;
        wymierna test4 = test - test2;
        wymierna test5 = test * test2;
        wymierna test6 = test / test2;
        wymierna test7 = !test;
        wymierna test8 = -test;
        cout << test3 << endl;
        cout << test4 << endl;
        cout << test5 << endl;
        cout << test6 << endl;
        cout << test7 << endl;
        cout << test8 << endl;
        cout << test << endl;
    }

    catch (DzieleniePrzezZero& er)
    {
        cerr << er.what();
    }

    catch (PrzekroczenieZakresu& er)
    {
        cerr << er.what();
    }
    return 0;
}