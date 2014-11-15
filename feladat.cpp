/*
Feladatkiírás

A feladat olyan osztálysablon írása, amely prioritási sor adatszerkezetet 
valósít meg. A sorba beszúrható elemek típusát és a rendezést a sablon 
paraméterei határozzák meg. A prioritási sor az elemeit a rendezés szerint
növekvõ sorrendben tárolja, azaz legelöl a legkisebb elemet. A prioritási sor
méretét csak a rendelkezésre álló memória korlátozza, de a dinamikusan allokált
memória felszabadítását biztosítani kell!

A sablon legyen példányosítható egy (csak típus) és két (típus és rendezés) 
paraméterrel is. Amennyiben a rendezés paraméter nincs feltüntetve 
példányosításkor, úgy az alapértelmezett rendezés a < operátort
használja.

A prioritási sor adatszerkezetnek rendelkeznie kell elõre és hátrafelé haladó
iterátorokkal, és mindkettõnek kétirányúnak kell lennie. Azaz mindkét 
iterátortípusnak támogatnia kell a ++ és -- operátorokkal történõ léptetést is.
Az elõrefelé haladó iterátor a rendezés szerinti legkisebb elemtõl kell 
induljon, és a ++ mûvelet hatására a nagyobb elemek felé lépked (-- mûveletre
fordítva), míg a hátrafelé haladó iterátor (++ esetén) a legnagyobbtól halad a
legkisebb elem felé.

Az osztálysablon publikus interfésze (a sablon neve, a sablonparaméterezése, a 
publikus metódusainak szignatúrája) kötött, azaz legalább az alábbiaknak meg
kell felelnie (de amennyiben a feladatkiírás szükségessé teszi további publikus
metódusokkal, belsõ típusokkal bõvíthetõ, valamint az osztály törzsén kívül is 
szerepelhetnek további típusok, metódusok):

Változások az eredeti feladatkiíráshoz képest

1. Pontosításra került, hogy az iterator és reverse_iterator osztályoknak a 
   my_priqueue osztály belsõ osztályainak kell lenni (nem lehetnek globálisak).
2. Az elvárt publikus interfészbõl nemdefiniált mûködés miatt törlésre került a
   T& my_priqueue::operator[](int index);
   metódus .
*/

// === MEGVALÓSÍTANDÓ ===

/**
 * Az osztálysablon neve my_priqueue.
 * A sablon paraméterezése:
 *   - T: a sorba helyezhetõ elemek típusa
 *   - Comparator: típus, aminek példányai rendezést megvalósító 
 *                 függvényobjektumok
 */
template<class T, class Comparator>
class my_priqueue {
public:
    /** Belsõ osztály, amely az elõrehaladó iterátort valósítja meg. */
    class iterator;
    /** Belsõ osztály, amely a hátrafeléhaladó iterátort valósítja meg. */
    class reverse_iterator;
    /** A sablonpéldány rendelkezik default konstruktorral. */
    my_priqueue();
    /** Elem beszúrása a prioritási sorba a rendezésnek megfelelõ helyre. */
    void push(const T &item);
    /** A prioritási sor legelsõ elemének eltávolítása és visszaadása. */
    T pop();
    /** A prioritási sorban levõ elemek száma. */
    int size();

    /** Elõrehaladó kétirányú iterátor típus a prisor elemeinek bejárására. */
    class iterator;
    /** Hátrafelé haladó kétirányú iterátor típus a prisor elemeinek bejárására. */
    class reverse_iterator;
    /** Elõrehaladó iterátor a prisor legelsõ elemére. */
    iterator begin();
    /** Elõrehaladó iterátor a prisor utolsó utáni elemére. */
    iterator end();
    /** Hátrafelé haladó iterátor a prisor utolsó elemére. */
    reverse_iterator rbegin();
    /** Hátrafelé haladó iterátor a prisor elsõ elõtti elemére. */
    reverse_iterator rend();
};

// === MEGVALÓSÍTÁS VÉGE ===

/**
 * Minta osztály, ami definiálja azt a publikus interfészt, amivel a
 * my_priqueue sablon második paraméterének rendelkeznie kell (feltéve, hogy az
 * elsõ sablonparaméter int volt). Ezt az osztályt a beadott feladatban nem 
 * kell megvalósítani!
 */
struct comparator {
    /** 
     * Függvényhívás operátor felüldefiniálása, amely rendezést valósít meg. 
     * Visszatérési értéke igaz, ha a < b valamilyen rendezési reláció szerint.
     */
    bool operator()(const int &a, const int &b);
};

/** 
 * Példa a prisor néhány felhasználására. A beadott feladatban nem szabad
 * szerepelnie.
 */
int main() {
    my_priqueue<int> q1;
    q1.push(77);
    q1.push(27);
    q1.push(7);
    
    my_priqueue<int, comparator> q2;
    q2.push(31);
    q2.push(1977);

    return 0;
}


