//#include "lista.hpp"

using namespace std;

template <typename T>
lista<T>::lista()
{
    this->first = nullptr;
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
lista<T>::lista(lista &&obj) //przenoszenie
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
void lista<T>::wstaw(T element, int pozycja)
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
void lista<T>::usun(T element)
{
    node* pom = new node();
    pom = this->first;

    while(pom->next->elem!=element)
    {
        pom = pom->next;
    }

    node* temp = new node();
    temp = pom->next;
    pom->next = pom->next->next;
    delete temp;
}

template <typename T>
T lista<T>::znajdz(T element)
{
    node* pom = new node();
    pom = this->first;

    while (pom->elem != element)
    {
        pom = pom->next;
    }
    
    return pom->elem;
}


template <typename T>
int lista<T>::ilosc()
{
    return this->size;
}

//template <typename T>
/*ostream& operator<< (ostream& wyj, const lista<T>& obj) //operator wypisania
{
    if (obj.first)
    {
        wyj << "Lista: ";
        node* temp = obj.first;
        while (temp)
        {
            wyj << temp->elem << ', ';
            temp = temp->next;
        }
    }
    else wyj << "Pusta lista";
    return wyj;
}*/  //do naprawienia




