void isNaN(double number) {
    if (double.IsNaN(number))
        Console.WriteLine("Število " + number + " je NaN");
    else
        Console.WriteLine("Število " + number + " ni NaN");
}

void isNaN_bitnoPreverjeno(double number){ 
// Pretvori double v 64-bitno celo število. Tukaj dobimo direkten dostop do bitov v pomnilniku.
    long bits = BitConverter.DoubleToInt64Bits(number);
    
// [ sign ][ exponent ][ mantissa ]
// 1 bit     11 bitov    52 bitov
// Začasno premaknemo bite za 52 mest desno,
//000000000000[sign][exponent]
    long exponent = (bits >> 52) & 0x7FF; //s tem dosežemo da & primerja in odreže zeksponent
// 0x7FF v binarnem: 11111111111

    long mantissa = bits & 0xFFFFFFFFFFFFF; // 0xFFFFFFFFFFFFF = 52 enic binarno
    
    if (exponent == 0x7FF && mantissa != 0) //glej README
        Console.WriteLine("Število " + number + " je NaN");
    else
        Console.WriteLine("Število " + number + " ni NaN");
}

Console.WriteLine(double.IsNaN(0.0/0.0)); // True
double st = double.NaN; 
isNaN(st); // Število NaN je NaN
isNaN(55.21); // Število 55,21 ni NaN
isNaN(-3); // Število -3 ni NaN

isNaN_bitnoPreverjeno(st); // Število NaN je NaN
isNaN_bitnoPreverjeno(55.21); // Število 55,21 ni NaN
isNaN_bitnoPreverjeno(-3); // Število -3 ni NaN
