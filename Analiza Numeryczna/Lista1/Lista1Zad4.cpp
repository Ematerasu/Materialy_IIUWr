#include <iostream>
#include <math.h>

using namespace std;


int main()
{
    float I[21];
    I[0] = log(2021.0/2020.0);
    cout<<I[0]<<endl;

    for(int i = 1; i<=20;i++)
    {
        I[i] = 1.0/i - 2020*I[i-1];
        cout<<I[i]<<endl;
    }


    return 0;
}