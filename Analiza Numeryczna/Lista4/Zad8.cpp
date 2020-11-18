#include <iostream>
#include <cmath>

using namespace std;

double newton(double x, int krok=1) { 
    double x1 = x - 8*pow((x-1), 8)*(x+1)/((8*pow((x-1), 7))*(x+1)+(pow((x-1), 8)));
    cout<<"x_n+1 = "<<x1<<" dla kroku nr "<<krok<<endl;
    if(abs(1-x1)<=pow(10,-5)) return x1;
    else newton(x1, krok+1);

}

double newton2(double x, int krok=1) { 
    double x1 = x - (x-1)*(pow((x+1), 1.0/8))/((pow((x+1), 1.0/8))+(x-1)*(1.0/8)*pow((x+1), -7.0/8));
    cout<<"x_n+1 = "<<x1<<" dla kroku nr "<<krok<<endl;
    if(abs(1-x1)<=pow(10,-5)) return x1;
    else newton2(x1, krok+1);

}


int main() {

    double f = newton(0.23);
    cout<<endl;
    double f2 = newton(1.26);
    cout<<endl;
    double f3 = newton(-0.1);

    cout<<endl;
    cout<<endl;

    double f4 = newton2(0.23);
    cout<<endl;
    double f5 = newton2(1.26);
    cout<<endl;
    double f6 = newton2(-0.1);

    return 0;
}