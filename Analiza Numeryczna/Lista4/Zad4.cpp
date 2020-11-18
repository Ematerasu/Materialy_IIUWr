#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double bisection(double a, double b, int krok=1) {
    double m = (a+b)/2;
    cout<<fixed<<setprecision(10)<<"Dla m = "<<m<<" wartosc f wynosi = "<<m*m-2*cos(3*m+1)<<" dla kroku nr "<<krok<<endl;

    if(abs(m*m-2*cos(3*m+1)) <= pow(10, -5)) return m;
    else if((a*a-2*cos(3*a+1))*(m*m-2*cos(3*m+1)) < 0) return bisection(a, m, krok+1);
    else if((b*b-2*cos(3*b+1))*(m*m-2*cos(3*m+1)) < 0) return bisection(m, b, krok+1);
}


int main() {

    double f = bisection(-1.0, 0.0);

    return 0;
}