#include <stdio.h>
#include <stdlib.h>
#include "Ulamki.c"

int main()
{
    Ulamek *u1, *u2, *u, *u3;

    u1=nowy_ulamek(3, -9);
    u2=nowy_ulamek(7, 3);

    dodaj_mod(u1, u2);
    printf("%d/%d\n", u2->licznik, u2->mianownik);
    free(u2);
    u2=nowy_ulamek(7, 3);

    odejmij_mod(u1, u2);
    printf("%d/%d\n", u2->licznik, u2->mianownik);
    free(u2);
    u2=nowy_ulamek(7, 3);
    dzielenie_mod(u1, u2);
    printf("%d/%d\n", u2->licznik, u2->mianownik);
    free(u2);
    u2=nowy_ulamek(7, 3);
    mnozenie_mod(u1, u2);
    printf("%d/%d\n", u2->licznik, u2->mianownik);
    free(u2);
    u2=nowy_ulamek(7, 3);

    printf("\n");
    u=dodaj_wsk(u1, u2);
    printf("%d/%d\n", u->licznik, u->mianownik);
    u=odejmij_wsk(u1, u2);
    printf("%d/%d\n", u->licznik, u->mianownik);
    u=dzielenie_wsk(u1, u2);
    printf("%d/%d\n", u->licznik, u->mianownik);
    u=mnozenie_wsk(u1, u2);
    printf("%d/%d\n", u->licznik, u->mianownik);

    return 0;
}
