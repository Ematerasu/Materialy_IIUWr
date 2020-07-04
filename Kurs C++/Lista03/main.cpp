#include <iostream>
#include <string>
#include <vector>
#include <exception>

std::string bin2rom(int x)
{
    const std::vector<std::pair<int, std::string>> rzym =
    {
        {1000, "M"},
        {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std:: string wynik = "";

    for(unsigned int i=0; i<rzym.size(); i++)
    {
        if(x-rzym[i].first >= 0) //Sprawdzam czy uzyskalem juz te liczbe
        {
            x = x - rzym[i].first;
            wynik = wynik + rzym[i].second;
            i--; //Musze cofnac indeks zeby cyfry rzymskie mogly sie powtorzyc
        }
    }
    return wynik;
}

int main(const int argc, const char* argv[])
{
    int liczba;

    for(int i=1; i<argc; i++)
    {
        try
        {
            liczba = std::stoi(argv[i]);

                if(liczba >= 1 && liczba <= 3999)
            {
                std::cout<<bin2rom(liczba)<<"\n";;
            }
            else
            {
                std::cout<<"Liczba "<<liczba<<" spoza zakresu!\n";
            }

        }
        catch (std::logic_error&)
        {
            std::clog<<"Niepoprawny argument!\n";

        }
    }

    return 0;
}
