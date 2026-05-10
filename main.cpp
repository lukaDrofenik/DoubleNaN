#include <iostream>
#include <math.h> //vklučuje isnan() in NAN
using namespace std;

void isNaN(double x) {
    if (isnan(x))
        cout << "Število " << x << " je NaN" << endl;
    else
        cout << "Število " << x << " ni NaN" << endl;
}

void isNaN_bitnoPreverjeno(double x){
  //TODO
}

int main() {

    cout << isnan(0.0/0.0) << endl; // 1
    double st = NAN;
    isNaN(st); // Število nan je NaN
    isNaN(55.21); // Število 55.21 ni NaN
    isNaN(-3); // Število -3 ni NaN

    return 0;
}
