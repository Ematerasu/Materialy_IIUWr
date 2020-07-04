#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <limits>

std::string CharToString(const char* wejscie)
{
    std::string wynik(wejscie);
    return wynik;
}

bool CzyPierwsza(int64_t liczba)
{
    for(int64_t i=2;i<=sqrt(liczba);i++)
    {
        if(liczba%i==0) return false;
    }
    return true;
}

int64_t Konwersja(const char *wejscie)
{
    int znak=1;
    int64_t wynik=0;

    if(*wejscie=='-')
    {
        znak=-1;
        wejscie++;
    }

    std::string liczba=CharToString(wejscie);
    int iter=0;



    while(iter<(int)liczba.length())
    {
        if(liczba[iter]<48 || liczba[iter]>57)
        {
            std::cout<<"Niepoprawna liczba! ";
            return 0;
        }

        wynik=((liczba[iter])-48)+wynik*10;
        iter++;
    }
    return wynik*znak;
}

std::vector<int64_t> pierwsza(int64_t liczba)
{
    std::vector<int64_t> liczby_pierwsze;

    if(CzyPierwsza(liczba))
    {
        if(liczba!=1) liczby_pierwsze.push_back(liczba);
        return liczby_pierwsze;
    }

    for(int64_t i=2;i<=sqrt(liczba);i++)
    {
        while(liczba%i==0)
        {
            liczby_pierwsze.push_back(i);
            liczba/=i;
        }
    }

    if(liczba!=1) liczby_pierwsze.push_back(liczba);

    return liczby_pierwsze;
}

void rozklad(int64_t liczba)
{
    std::cout<<liczba<<" = ";
    std::vector<int64_t> x;

    if(liczba==std::numeric_limits<int64_t>::min() || liczba==std::numeric_limits<int64_t>::max())
    {
        std::cout<<liczba<<" Przekroczono zakres!\n";
        return;
    }

    if(liczba<0)
    {
        if(liczba!=-1)
        {
            std::cout<<"-1 * ";
            liczba*=-1;
        }
        else
        {
            std::cout<<"-1";
            liczba*=-1;
            return;
        }
    }
    else if(liczba==0)
    {
        std::cout<<"0";
        return;
    }
    else if(liczba==1)
    {
        std::cout<<"1";
        return;
    }

    x=pierwsza(liczba);

    if(x.back()!=1)
    {
        std::cout<<x.back();
        liczba/=x.back();
        x.pop_back();
    }
    else if(x.back()==1)
    {
        std::cout<<x.back();
        x.pop_back();
    }

    for(int64_t i : x)
    {
        if(i!=1)
        {
            std::cout<<" * "<<i;
            liczba/=i;
        }
        else if(i==1)
        {
            std::cout<<" * "<<liczba;
            break;
        }
    }

}

int main(int argc, char *argv[])
{
   if(argc<2)
   {
       std::cerr<<"Bledne dane!\n";
       std::cerr<<"Instrukcja: Zadanie1.exe liczba1 liczba2 ...\n";
       exit(1);
   }
   for(int i=0;i<argc-1;i++)
   {
       rozklad(Konwersja(argv[i+1]));
       std::cout<<"\n";
   }

    return 0;
}
