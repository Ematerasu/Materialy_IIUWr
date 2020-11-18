#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return 4*cos(x)*cos(x)-3;
}

double f_better(double x){
    return 4*(1 - sin(x)*sin(x))-3;
}

int main() {

    cout<<"Oryginalna funkcja: "<<f(M_PI/6.0)<<endl;
    cout<<"Usprawniona: "<<f_better(M_PI/6.0)<<endl;

    cout<<"Wartosc 4*cos^2(x) dla pi/6 = "<<setprecision(20)<<4*cos(M_PI/6.0)*cos(M_PI/6.0)<<endl;
    cout<<"To samo dla 4*(1-sin^2(x)) = "<<setprecision(20)<<4*(1-sin(M_PI/6.0)*sin(M_PI/6.0))<<endl;
    return 0;
}