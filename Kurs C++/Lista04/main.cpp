#include <iostream>
#include "stos.hpp"

int main()
{
    int pojemnosc;
    std::cout << "Podaj rozmiar twojego stosu\n";
    std::cin >> pojemnosc;

    Stos *Orig_Stos = new Stos(pojemnosc);

    string elem;
    int lever;


    while (lever!=7)
    {
        std::cout << "\n\nMozliwe akcje:\n";
        std::cout << "1.Pokaz pojemnosc stosu\n";
        std::cout << "2.Pokaz ilosc jest elementow na stosie\n";
        std::cout << "3.Wstaw element na stos\n";
        std::cout << "4.Zdejmij element ze szczytu stosu\n";
        std::cout << "5.Pokaz element ze szczytu stosu\n";
        std::cout << "6.Obroc stos\n";
        std::cout << "7.Zakoncz program\n";

        std::cin >> lever;
        switch (lever) {
        case 1:
        {
            system("clear");
            std::cout << "Pojemnosc stosu wynosi : " << Orig_Stos->get_poj() << "\n";
            break;
        }
        case 2:
        {
            system("clear");
            std::cout << "Ilosc elementow na stosie : " << Orig_Stos->rozmiar() << "\n";
            break;
        }
        case 3:
        {
            system("clear");
            if(Orig_Stos->get_ile() == Orig_Stos->get_poj())
            {
                cout << "Maksymalny rozmiar stosu osiagniety!" << endl;
                break;
            }

            std::cout << "Jaki element wstawic?" << endl;
            std::cin >> elem;

            Orig_Stos->wloz(elem);
            std::cout << "Dodano element " << elem <<
                " na pozycje " << Orig_Stos->rozmiar() << "\n";
            break;
        }
        case 4:
        {
            system("clear");
            if(Orig_Stos->get_ile()==0)
            {
                std::cout << "Na stosie nic nie ma! " << endl;
                break;
            }
            std::cout << "Sciagam element " << Orig_Stos->sciagnij() <<
                " ze stosu" << "\n";
            break;
        }
        case 5:
        {
            system("clear");
            if(Orig_Stos->get_ile() == 0)
            {
                std::cout << "Na stosie nic nie ma! " << endl;
                break;
            }
            std::cout << "Na szczycie stosu mamy " << Orig_Stos->sprawdz() << "\n";
            break;
        }
        case 6:
        {
            system("clear");
            Orig_Stos = Orig_Stos->Odwroc();
            std::cout << "Obrocono stos " << "\n";
            break;
        }
        case 7:
        {
            system("clear");
            delete[] Orig_Stos;
            break;
        }
        default:
        {
            system("clear");
            std::cout << "Bledny wybor" << endl;
        }
        }

        
    }
    return 0;
}
