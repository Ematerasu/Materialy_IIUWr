#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;


int main()
{
    double wynik = 4;
    
    for(int i = 1; i<=200000; i++)
    {
        wynik += 4*(pow(-1, i)/(2*i+1));
        /*if(abs(M_PI - wynik) < pow(10, -4))
        {
            cout<<i<<endl;
            break;
        }*/
    }

    cout<<wynik<<endl;



    return 0;
}