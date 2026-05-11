#include <iostream>
#include <math.h> //vklučuje isnan() in NAN
#include <cstdint>  //uint64_t     dobimo podatkovni tip unsigned 64-bit integer
#include <cstring>  //memcpy       funkcija ki kopira surove bajte iz enega dela pomnilnika v drugega
using namespace std;

void isNaN(double x) {
    if (isnan(x))
        cout << "Stevilo " << x << " je NaN" << endl;
    else
        cout << "Stevilo " << x << " ni NaN" << endl;
}

void isNaN_bitnoPreverjeno(double x){
    uint64_t bits;
    // Prekopira bite iz double v uint64_t. (direkten dostop do bitov)
    memcpy(&bits, &x, sizeof(bits)); //sizeof je zato da program ve koliko bitov mora kopirati

    // [ sign ][ exponent ][ mantissa ]
    // 1 bit     11 bitov    52 bitov
    // Začasno premaknemo bite za 52 mest desno, da exponent pride na konec.
    uint64_t exponent = (bits >> 52) & 0x7FF; // 0x7FF v binarnem 11111111111

    // Vzamemo 52 bitov na enak način kot eksponent
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

    // IEEE 754 pravilo za NaN: exponent = same 1 && mantissa != 0
    if (exponent == 0x7FF && mantissa != 0)
        cout << "Stevilo "<< x <<" je NaN" << endl;
    else
        cout << "Stevilo "<< x <<" ni NaN" << endl;
}

int main() {

    cout << isnan(0.0/0.0) << endl; // 1
    double st = NAN;
    isNaN(st); // Število nan je NaN
    isNaN(55.21); // Število 55.21 ni NaN
    isNaN(-3); // Število -3 ni NaN

    isNaN_bitnoPreverjeno(0.0/0.0); // Število nan je NaN
    isNaN_bitnoPreverjeno(st); // Število nan je NaN
    isNaN_bitnoPreverjeno(55.21); // Število 55,21 ni NaN
    isNaN_bitnoPreverjeno(-3); // Število -3 ni NaN

    return 0;
}
