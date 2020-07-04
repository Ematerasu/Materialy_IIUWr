#ifndef ULAMKI_H_INCLUDED
#define ULAMKI_H_INCLUDED

typedef struct u{

    int licznik;
    int mianownik;

} Ulamek;

Ulamek *nowy_ulamek(int licznik, int mianownik);
//Rozwiazanie na wskaznikach
Ulamek *dodaj_wsk(Ulamek *u1, Ulamek *u2);
Ulamek *odejmij_wsk(Ulamek *u1, Ulamek *u2);
Ulamek *mnozenie_wsk(Ulamek *u1, Ulamek *u2);
Ulamek *dzielenie_wsk(Ulamek *u1, Ulamek *u2);

//Rozwiazanie na modyfikacji drugiego argumentu
void dodaj_mod(Ulamek *u1, Ulamek *u2);
void odejmij_mod(Ulamek *u1, Ulamek *u2);
void mnozenie_mod(Ulamek *u1, Ulamek *u2);
void dzielenie_mod(Ulamek *u1, Ulamek *u2);


//Pomocnicze funkcje
int NWD(int a, int b);
void skracanie(Ulamek *u);

#endif // ULAMKI_H_INCLUDED
