#include <iostream>
#include <cmath>

using namespace std;

double fact(int n) {
    if(n == 1) return 1;
    else return n*fact(n-1);
}

double f1(double x) {
    return pow(x, 3) - sqrt( pow(x, 6) + 2020);
}

double f1_better(double x) {
    return -2020/(pow(x, 3)+sqrt(pow(x, 6) + 2020));
}

double f2(double x) {
    return pow(x, -4)*(cos(x)-1+pow(x, 2)/2);
}

double f2_better(double x) {
    return 1/fact(4) - pow(x, 2)/fact(6) + pow(x, 4)/fact(8) - pow(x, 6)/fact(8) + pow(x, 8)/fact(10);
}

double f3(double x) {
    return log(x)/log(5) - 6;
}

double f3_better(double x) {
    return log(x/pow(5,6))/log(5);
}

int main() {

    double func1 = f1(pow(10, 10));
    double func1_better = f1_better(pow(10, 10));
    double func2 = f2(pow(10, -20));
    double func2_better = f2_better(pow(10, -20));
    double func3 = f3(pow(5, 0));
    double func3_better = f3_better(pow(5, 0));

    cout<<func1<<endl;
    cout<<func1_better<<"\n"<<endl;
    cout<<func2<<endl;
    cout<<func2_better<<"\n"<<endl;
    cout<<func3<<endl;
    cout<<func3_better<<endl;


    return 0;
}