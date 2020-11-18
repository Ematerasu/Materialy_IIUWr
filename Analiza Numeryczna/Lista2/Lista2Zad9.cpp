#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double x[1000];
    x[1] = 2;

    /*for(int k = 1; k < 100; k++) {

        x[k+1] = pow(2, k)*sqrt( 2*( 1-sqrt( 1 - pow(( x[k]/pow(2, k) ), 2) ) ) );
        cout<<k+1<<". "<<x[k+1]<<endl;

    }*/

    /*for(int k = 1; k < 1000; k++) {

        x[k+1] = sqrt( (2*pow(x[k], 2))/ ( 1 + sqrt( 1 - pow( x[k]/pow(2, k), 2 ) ) ) );
        cout<<k+1<<". "<<x[k+1]<<endl;

    }*/

    return 0;
}