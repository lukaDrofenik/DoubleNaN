# DoubleNaN
V tej nalogi se osredotočamo na NaN vrednost v podatkovnem tipu Double. V jezikih C# in C++

V osnovi NaN ni enako NaN, zato `NaN == NaN -> False`<br>
Tako je definirano po IEEE 754 standardu.<br>
Razlog: NaN predstavlja neveljaven/nerazločen rezultat (npr. 0/0, sqrt(-1)). Če bi NaN ravnal kot katerakoli konkretna vrednost, bi to lahko zavajalo pri detekciji napak in neveljavnih rezultatov, zato standard zahteva, da primerjava vrne false za enakost. <br>
Zato ima C# funkcijo `double.IsNaN()`, <br>
C++ pa z `#include <math.h>` dobi funkcijo isNaN()<br>
Deklaracija: C#: `double st = double.NaN;`,<br>
C++: `double st = NAN;`

### Preverjanje brez funkcije isNaN
Po standardu IEEE 754 se **double** shranjuje na sledeči način:<br>
(sign | exponent | mantissa)<br>
(1 bit predznak | 11 bitov eksponent | 52 bitov števila)<br>
Tako double zasede 8 bajtov pomnilnika

To nam pove, da lahko NaN preverjamo tudi na bitnem nivoju.<br>
Prvi pogoj (eksponent):<br>
**Če so v eksponentu same 1 kot je spodaj. Potem gre za "special value"** 
Drugi pogoj (mantissa):<br>
Pri shranjeni vrednosti **NaN** mantissa != 0<br>
Če pa mantissa == 0 potem je vrednost Infinity. **Double ima še več "special values"**<br>
NaN v pomnilniku izgleda tako: sign | 11111111111 | nonzero mantissa<br>

# English
In this task, we focus on the NaN value in the Double data type. In C# and C++

Basically, NaN is not the same as NaN, so `NaN == NaN -> False`<br>
This is defined in the IEEE 754 standard.<br>
Reason: NaN represents an invalid/undifferentiated result (e.g. 0/0, sqrt(-1)). If NaN were to behave like any concrete value, it could mislead error detection and invalid results, so the standard requires that the comparison return false for equality. <br>
That's why C# has the `double.IsNaN()` function, <br>
C++ has the `#include <math.h>` function isNaN()<br>
Declaration: C#: `double st = double.NaN;`,<br>
C++: `double st = NAN;`

### Checking without the isNaN function
According to the IEEE 754 standard, **double** is stored in the following way:<br>
(sign | exponent | mantissa)<br>
(1 bit sign | 11 bits exponent | 52 bits number)<br>
Thus, double occupies 8 bytes of memory

This tells us that we can also check for NaN at the bit level.<br>
First condition (exponent):<br>
**If the exponent contains only 1s as shown below. Then it is a "special value"**
Second condition (mantissa):<br>
For the stored value **NaN** mantissa != 0<br>
But if mantissa == 0 then the value is Infinity. **Double has even more "special values"**<br>
NaN in memory looks like this: sign | 11111111111 | nonzero mantissa<br>
