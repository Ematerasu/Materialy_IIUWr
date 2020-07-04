#include <iostream>
#include "Zadanie1.hpp"

//Kompilacja w terminalu:
// g++ -std=c++11 -Wall -Wextra -pedantic main.cpp Zadanie1.cpp Zadanie1.hpp -o Lista2.exe


int main()
{

    punkt Punkt1(4, 6);
    wektor Wektor1(3, -1);
    punkt Punkt2(Punkt1, Wektor1);
    wektor Wektor2(8, 3);
    prosta Prosta1(Punkt1, Punkt2);
    prosta Prosta2(8, 9, 19);
    prosta Prosta3(Prosta2, Wektor2);
    prosta Prosta4(8, 9, 5);
    prosta Prosta5(-0.125, 9, 12);

    std::cout<<"Punkt1: "<<Punkt1.x<<", "<<Punkt1.y<<"\n";
    std::cout<<"Punkt2: "<<Punkt2.x<<", "<<Punkt2.y<<"\n";
    std::cout<<"Wektor1: "<<Wektor1.dx<<", "<<Wektor1.dy<<"\n";
    std::cout<<"Wektor2: "<<Wektor2.dx<<", "<<Wektor2.dy<<"\n";
    std::cout<<"Prosta1: "<<Prosta1.get_A()<<", "<<Prosta1.get_B()<<", "<<Prosta1.get_C()<<"\n";
    std::cout<<"Prosta2: "<<Prosta2.get_A()<<", "<<Prosta2.get_B()<<", "<<Prosta2.get_C()<<"\n";
    std::cout<<"Prosta3: "<<Prosta3.get_A()<<", "<<Prosta3.get_B()<<", "<<Prosta3.get_C()<<"\n";
    std::cout<<"Prosta4: "<<Prosta4.get_A()<<", "<<Prosta4.get_B()<<", "<<Prosta4.get_C()<<"\n";
    std::cout<<"Prosta5: "<<Prosta5.get_A()<<", "<<Prosta5.get_B()<<", "<<Prosta5.get_C()<<"\n";


    std::cout<<"Czy Prosta2 i Prosta4 sa rownolegle? "<<Czy_rownolegle(Prosta2, Prosta4)<<"\n";
    std::cout<<"Czy Prosta2 i Prosta4 sa prostopadle? "<<Czy_prostopadle(Prosta2, Prosta4)<<"\n";
    std::cout<<"Czy Prosta4 i Prosta5 sa prostopadle? "<<Czy_prostopadle(Prosta4, Prosta5)<<"\n";
    std::cout<<"Punkt przeciecia prostych Prosta4 i Prosta5: ";
    Punkt_przeciecia(Prosta4, Prosta5);
    std::cout<<"Punkt przeciecia prostych Prosta2 i Prosta4: ";
    Punkt_przeciecia(Prosta2, Prosta4);


    return 0;
}
