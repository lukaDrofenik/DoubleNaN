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
