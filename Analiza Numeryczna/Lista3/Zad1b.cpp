#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, -3)*(atan(x)-x);
}

double f_better(double x){
    return -1.0/3.0+pow(x, 2)/5-pow(x,4)/7+pow(x,6)/9;
}

int main(){

    cout<<f(0.00000001)<<endl;

    cout<<endl;
    cout<<endl;

    cout<<f_better(0.00000001)<<endl;
    return 0;
}