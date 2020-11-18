#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    double a = 1.0;
    double b = 10000000000.0;
    double c = 1.0;

    cout<<"x1 = "<<(-b-sqrt(b*b-4*c*a))/2*a<<endl;
    cout<<"x2 = "<<(-b+sqrt(b*b-4*c*a))/2*a<<endl;

    cout<<"x2 ze wzorow viete'a = "<<2*c/(-b-sqrt(b*b-4*c*a))<<endl;

   return 0;
}