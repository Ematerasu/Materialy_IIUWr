#ifndef LISTA_HPP_INCLUDED
#define LISTA_HPP_INCLUDED
#include <iostream>
#include <initializer_list>
#include <string>

/*
    Definiuje funkcje w tym samym pliku poniewaz przy definiowaniu ich w pliku lista.cpp nastapil problem referencji itp.
    Rozwiazanie ktore znalazlem w internecie zalecalo definiowanie tych funkcji w tym samym pliku co ich deklaracja, wiec tak zrobilem.

    Nie rozumiem za bardzo pojecia trejtow wiec nie robilem metod check() i sort()
*/

using namespace std;
template <typename T>
class lista
{
public:
    class node;

protected:
    node* first;
    int size;
public:
    lista();
    lista(initializer_list<T> l);
    lista(const lista& obj);
    lista(lista &&obj);

    void wstaw(T element, int pozycja);
    void usun(T element);
    string znajdz(T element);
    int ilosc();

    //friend ostream& operator<< (ostream& wyj, const lista& obj);

    //bool check();
    //void sort();
};
template <typename T>
class lista<T>::node
{
public:
    T elem;
    node* next;

    node() : next(nullptr) { ; };
};

template <typename T>
lista<T>::lista()
{
    this->first = new node();
    this->size = 0;
}

template <typename T>
lista<T>::lista(const lista& obj) //kopiowanie
{
    this->size = obj.ilosc();
    node* temp = obj.first;
    this->first = new node(*temp);
    node* temp2 = first;
    while (temp)
    {
        temp->next = new node(*temp->next);
        temp = temp->next;
        temp2 = temp->next;
    }
}
template <typename T>
lista<T>::lista(lista&& obj) //przenoszenie
{
    this->size = obj.size;
    obj.size = 0;
    this->first = obj.first;
    obj.first = nullptr;
}

template <typename T>
lista<T>::lista(initializer_list<T> l) //konstrukcja z listy
{
    node* temp;
    this->first = temp;
    for (const T& x : l)
    {
        temp->elem = x;
        temp = temp->next;
    }
}

template <typename T>
void lista<T>::wstaw(T element, int pozycja) //dodawanie elementu na dana pozycje
{
    node* new_one = new node();
    new_one->elem = element;

    node* pom = new node();
    pom = this->first;

    for (int i = 1; i < pozycja; i++)
    {
        pom = pom->next;
    }

    node* temp = new node();
    temp = pom->next;
    pom->next = new_one;
    new_one->next = temp;

    this->size++;
}

template <typename T>
void lista<T>::usun(T element) //usuwanie elementu
{
    node* pom = new node();
    pom = this->first;

    while (pom->next->elem != element)
    {
        pom = pom->next;
    }

    node* temp = new node();
    temp = pom->next;
    pom->next = pom->next->next;
    this->size--;
    delete temp;
}

template <typename T>
string lista<T>::znajdz(T element) //wyszukiwanie elementu na liscie i podawanie jego pozycji
{
    node* pom = new node();
    pom = this->first;
    int pozycja = 0;

    while (pom->elem != element && pom)
    {
        pom = pom->next;
        pozycja++;
    }

    if (pom == nullptr)
        cerr << "Nie ma tego elementu na liscie";

    string wynik = to_string(pom->elem) + " na pozycji " + to_string(pozycja) + "\n";

    return wynik;
}


template <typename T>
int lista<T>::ilosc() //ilosc elementow na liscie
{
    return this->size;
}

/*template <typename T>
ostream& operator<< (ostream& wyj, const lista<T>& obj) //operator wypisania
{
    if (obj.first)
    {
        wyj << "Lista: ";
        node* temp = new node();
        temp = obj.first;
        while (temp)
        {
            wyj << temp->elem << ', ';
            temp = temp->next;
        }
    }
    else wyj << "Pusta lista";
    return wyj;
}*/  //do naprawienia

#endif