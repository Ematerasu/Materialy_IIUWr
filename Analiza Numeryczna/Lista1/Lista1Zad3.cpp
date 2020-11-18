#include <iostream>
#include <math.h>

using namespace std;


int main()
{
    double y[51];
    y[0] = 1;
    y[1] = -1.0/7.0;
    cout<<"0. "<<y[0]<<endl;
    cout<<"1. "<<y[1]<<endl;

    for(int i = 2; i <= 50; i++)
    {
        y[i] = 1.0/7.0*(69.0*y[i-1] + 10.0*y[i-2]);
        cout<<i<<". "<<y[i]<<endl;

    }


    return 0;
}