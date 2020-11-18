#include <iostream>
#include <math.h>

using namespace std;

void func_single()
{
    float x = 0.001;

    float wynik = 4040*((sqrt(pow(x, 11)+1)-1 )/ pow(x, 11));

    cout<<"Single =  "<<wynik<<endl;
}

void func_double()
{
    double x = 0.001;

    double wynik = 4040*((sqrt(pow(x, 11)+1)-1 )/ pow(x, 11));

    cout<<"Double =  "<<wynik<<endl;
}

int main()
{
    func_single();
    func_double();
    

    return 0;
}