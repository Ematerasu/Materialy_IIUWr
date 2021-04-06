#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    long long int m , n, d;
    int wynik = 0;
    int iter = 0;
    cin >> m;
    pair<long long int, long long int> tab[m];
    for(int i = 0; i < m; i++){
        cin >> d >> n;
        tab[i] = make_pair(d, n);
    }
    int pom = sizeof(tab)/sizeof(tab[0]);
    sort(tab, tab+pom);
    
    //Mimo ze Jas laczy najdluzsze sznurki to przechodze tablice od najmniejszych wartosc w wypadku
    //gdyby mniejsze sznurki po polaczeniu mialy dlugosc jak inny sznurek ktory juz "zrobilem", wtedy mam pewnosc ze nie pomine jakiegos sznurka (Bo nie powstana mniejsze dlugosci niz aktualnie najmniejsza)
    while(iter < m){
        //Jezeli sznurkow jest nieparzysta ilosc, to mamy pewnosc ze zostanie 1 unikalny sznurek wiec dopisuje do wyniku +1, usuwam ten jeden sznurek ze zbioru a reszte zlaczam nizej (o ile jest co zlaczac)
        if(tab[iter].second % 2 == 1){
            wynik++;
            tab[iter].second--;
        }
        //Jezeli dalej jakies sznurki sa to laczymy je wszystkie w pary tj. dwa razy wieksza dlugosc, dwa razy mniejsza ilosc
        if(tab[iter].second != 0){
            tab[iter].first *= 2;
            tab[iter].second /= 2;

            //Jezeli po polaczeniu powstaly sznurki o dlugosc ktora jest juz w zbiorze to zwiekszy tamten zbior,
            //Wiec trzeba znalesc w naszej liscie czy ewentualnie takiej dlugosc juz nie ma
            //Wyszukiwanie liniowe jest zbyt kosztowne (TLE na sprawdzaczce :( ) wiec skorzystam z binsearcha
            int indeksDolny = iter+1;
            int indeksGorny = m-1;
            
            while(indeksDolny <= indeksGorny){
            
                int s = (indeksDolny+indeksGorny)/2;

                if(tab[s].first == tab[iter].first){
                    tab[s].second += tab[iter].second;
                    iter++;
                    break;
                }

                if(tab[s].first < tab[iter].first){
                    indeksDolny = s+1;
                }
                else{
                    indeksGorny = s-1;
                }
            }
        }
        //Jesli sie skonczyly sznurki danej dlugosci to idziemy dalej
        else if(tab[iter].second == 0) iter++;
    }

    cout<<wynik;

    return 0;
}