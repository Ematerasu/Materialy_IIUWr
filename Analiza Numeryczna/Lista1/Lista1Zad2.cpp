#include <iostream>
#include <math.h>
#include <float.h>
#include <limits>

using namespace std;

void func_single()
{
    float x = 10;
    float temp;

    for(int i =1; i<=20; i++)
    {
        temp = pow(x, -i);

        cout<<"Single for i = "<<i<< " "<<12120*((temp - sin(temp)) / pow(temp, 3))<<endl;
    }
}

void func_double()
{
    double x = 10;
    double temp;

    for(int i =2; i<=20; i++)
    {
        temp = pow(x, -i);

        cout<<"Double for i = "<<i<< " "<<12120*((temp - sin(temp)) / pow(temp, 3))<<endl;
    }

}

int main()
{
    func_single();
    func_double();
    

    return 0;
}