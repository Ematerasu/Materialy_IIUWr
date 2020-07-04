#ifndef WYMIERNE_H_INCLUDED
#define WYMIERNE_H_INCLUDED

typedef long long int Liczba_Wymierna;
Liczba_Wymierna Wczytaj(void);
Liczba_Wymierna Konstruuj(int licznik , int Mianownik);
void czytajW(int Licznik, int Mianownik);
int KonwersjaLicznik(Liczba_Wymierna x);
int KonwersjaMianownik(Liczba_Wymierna x);
Liczba_Wymierna Dodawanie(Liczba_Wymierna x, Liczba_Wymierna y);
Liczba_Wymierna Odejmowanie(Liczba_Wymierna x, Liczba_Wymierna y);
Liczba_Wymierna Mnozenie(Liczba_Wymierna x, Liczba_Wymierna y);
Liczba_Wymierna Dzielenie(Liczba_Wymierna x, Liczba_Wymierna y);



#endif // WYMIERNE_H_INCLUDED
