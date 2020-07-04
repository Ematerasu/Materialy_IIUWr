#ifndef ZADANIE2_H_INCLUDED
#define ZADANIE2_H_INCLUDED
#include <stdbool.h>

//Dominik Budzki Lista6 Zadanie2 314625


int cmpfunc (const void * a, const void * b) ;
void Generator(int n, double t[n]);
bool czy_Poprawny(int n, int t[n], int t2[n]);
void Sortowanie(int n, double t[n]);
void LicznikCzasu(void (*funkcja)(int, double*), int n);
void LicznikQCzasu(int n);


#endif // ZADANIE2_H_INCLUDED
