#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double x11 = pow(0.001, 11);

    double wynik = 4040*(sqrt(x11+1)-1)/x11;

    cout<<"Przed:"<<endl;
    cout<<x11<<endl;
    cout<<wynik<<endl;

    wynik = 4040/(sqrt(x11+1)+1);

    cout<<"\nPo:"<<endl;
    cout<<x11<<endl;
    cout<<wynik<<endl;

    return 0;
}