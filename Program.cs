void isNaN(double number) {
    if (double.IsNaN(number))
        Console.WriteLine("Število " + number + " je NaN");
    else
        Console.WriteLine("Število " + number + " ni NaN");
}

void isNaN_bitnoPreverjeno(double number){
    //TODO
}

Console.WriteLine(double.IsNaN(0.0/0.0)); // True
double st = double.NaN; 
isNaN(st); // Število NaN je NaN
isNaN(55.21); // Število 55,21 ni NaN
isNaN(-3); // Število -3 ni NaN
