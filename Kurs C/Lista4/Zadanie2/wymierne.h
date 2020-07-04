#ifndef WYMIERNE_H_INCLUDED
#define WYMIERNE_H_INCLUDED

//Dominik Budzki 314625 Lista4 Zadanie2


typedef long long int Liczba_Wymierna;
Liczba_Wymierna Wczytaj(void);
Liczba_Wymierna Konstruuj(int licznik , int Mianownik);
void czytajW(int Licznik, int Mianownik, int p);
int KonwersjaLicznik(Liczba_Wymierna x);
int KonwersjaMianownik(Liczba_Wymierna x);
Liczba_Wymierna Dodawanie(Liczba_Wymierna x, Liczba_Wymierna y);
Liczba_Wymierna Odejmowanie(Liczba_Wymierna x, Liczba_Wymierna y);
Liczba_Wymierna Mnozenie(Liczba_Wymierna x, Liczba_Wymierna y);
Liczba_Wymierna Dzielenie(Liczba_Wymierna x, Liczba_Wymierna y);
void Wczytywanie_wielomianu(int n, Liczba_Wymierna Wielomian[n]);
void Dodawanie_Wielomianu(int n1, int n2, Liczba_Wymierna Wielomian1[n1], Liczba_Wymierna Wielomian2[n2]);
void Odejmowanie_Wielomianu(int n1, int n2, Liczba_Wymierna Wielomian1[n1], Liczba_Wymierna Wielomian2[n2]);
void Mnozenie_Wielomianu(int n1, int n2, Liczba_Wymierna Wielomian1[n1], Liczba_Wymierna Wielomian2[n2], Liczba_Wymierna WielomianWynik[n1+n2]);
void Wartosc_wielomianu(int n, Liczba_Wymierna Wielomian[n]);
Liczba_Wymierna Potegowanie(Liczba_Wymierna Liczba, int Wykladnik);

#endif // WYMIERNE_H_INCLUDED
