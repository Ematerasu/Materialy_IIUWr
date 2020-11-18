#include <iostream>

using namespace std;

double bisection(double a, double b, int krok=1) {
    double m = (a+b)/2;
    cout<<"Dla m = "<<m<<" wartosc f wynosi = "<<m-0.49<<" dla kroku nr "<<krok<<endl;
    cout<<"Blad wynosi " <<0.49-m<<endl;

    if(krok == 5) return m;
    else if((a-0.49)*(m-0.49) < 0) return bisection(a, m, krok+1);
    else if((b-0.49)*(m-0.49) < 0) return bisection(m, b, krok+1);
}

int main() {

    double f = bisection(0.0, 1.0);

    return 0;
}