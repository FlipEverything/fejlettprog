/*
Feladatki�r�s

A feladat olyan oszt�lysablon �r�sa, amely priorit�si sor adatszerkezetet 
val�s�t meg. A sorba besz�rhat� elemek t�pus�t �s a rendez�st a sablon 
param�terei hat�rozz�k meg. A priorit�si sor az elemeit a rendez�s szerint
n�vekv� sorrendben t�rolja, azaz legel�l a legkisebb elemet. A priorit�si sor
m�ret�t csak a rendelkez�sre �ll� mem�ria korl�tozza, de a dinamikusan allok�lt
mem�ria felszabad�t�s�t biztos�tani kell!

A sablon legyen p�ld�nyos�that� egy (csak t�pus) �s k�t (t�pus �s rendez�s) 
param�terrel is. Amennyiben a rendez�s param�ter nincs felt�ntetve 
p�ld�nyos�t�skor, �gy az alap�rtelmezett rendez�s a < oper�tort
haszn�lja.

A priorit�si sor adatszerkezetnek rendelkeznie kell el�re �s h�trafel� halad�
iter�torokkal, �s mindkett�nek k�tir�ny�nak kell lennie. Azaz mindk�t 
iter�tort�pusnak t�mogatnia kell a ++ �s -- oper�torokkal t�rt�n� l�ptet�st is.
Az el�refel� halad� iter�tor a rendez�s szerinti legkisebb elemt�l kell 
induljon, �s a ++ m�velet hat�s�ra a nagyobb elemek fel� l�pked (-- m�veletre
ford�tva), m�g a h�trafel� halad� iter�tor (++ eset�n) a legnagyobbt�l halad a
legkisebb elem fel�.

Az oszt�lysablon publikus interf�sze (a sablon neve, a sablonparam�terez�se, a 
publikus met�dusainak szignat�r�ja) k�t�tt, azaz legal�bb az al�bbiaknak meg
kell felelnie (de amennyiben a feladatki�r�s sz�ks�gess� teszi tov�bbi publikus
met�dusokkal, bels� t�pusokkal b�v�thet�, valamint az oszt�ly t�rzs�n k�v�l is 
szerepelhetnek tov�bbi t�pusok, met�dusok):

V�ltoz�sok az eredeti feladatki�r�shoz k�pest

1. Pontos�t�sra ker�lt, hogy az iterator �s reverse_iterator oszt�lyoknak a 
   my_priqueue oszt�ly bels� oszt�lyainak kell lenni (nem lehetnek glob�lisak).
2. Az elv�rt publikus interf�szb�l nemdefini�lt m�k�d�s miatt t�rl�sre ker�lt a
   T& my_priqueue::operator[](int index);
   met�dus .
*/

// === MEGVAL�S�TAND� ===

/**
 * Az oszt�lysablon neve my_priqueue.
 * A sablon param�terez�se:
 *   - T: a sorba helyezhet� elemek t�pusa
 *   - Comparator: t�pus, aminek p�ld�nyai rendez�st megval�s�t� 
 *                 f�ggv�nyobjektumok
 */
template<class T, class Comparator>
class my_priqueue {
public:
    /** Bels� oszt�ly, amely az el�rehalad� iter�tort val�s�tja meg. */
    class iterator;
    /** Bels� oszt�ly, amely a h�trafel�halad� iter�tort val�s�tja meg. */
    class reverse_iterator;
    /** A sablonp�ld�ny rendelkezik default konstruktorral. */
    my_priqueue();
    /** Elem besz�r�sa a priorit�si sorba a rendez�snek megfelel� helyre. */
    void push(const T &item);
    /** A priorit�si sor legels� elem�nek elt�vol�t�sa �s visszaad�sa. */
    T pop();
    /** A priorit�si sorban lev� elemek sz�ma. */
    int size();

    /** El�rehalad� k�tir�ny� iter�tor t�pus a prisor elemeinek bej�r�s�ra. */
    class iterator;
    /** H�trafel� halad� k�tir�ny� iter�tor t�pus a prisor elemeinek bej�r�s�ra. */
    class reverse_iterator;
    /** El�rehalad� iter�tor a prisor legels� elem�re. */
    iterator begin();
    /** El�rehalad� iter�tor a prisor utols� ut�ni elem�re. */
    iterator end();
    /** H�trafel� halad� iter�tor a prisor utols� elem�re. */
    reverse_iterator rbegin();
    /** H�trafel� halad� iter�tor a prisor els� el�tti elem�re. */
    reverse_iterator rend();
};

// === MEGVAL�S�T�S V�GE ===

/**
 * Minta oszt�ly, ami defini�lja azt a publikus interf�szt, amivel a
 * my_priqueue sablon m�sodik param�ter�nek rendelkeznie kell (felt�ve, hogy az
 * els� sablonparam�ter int volt). Ezt az oszt�lyt a beadott feladatban nem 
 * kell megval�s�tani!
 */
struct comparator {
    /** 
     * F�ggv�nyh�v�s oper�tor fel�ldefini�l�sa, amely rendez�st val�s�t meg. 
     * Visszat�r�si �rt�ke igaz, ha a < b valamilyen rendez�si rel�ci� szerint.
     */
    bool operator()(const int &a, const int &b);
};

/** 
 * P�lda a prisor n�h�ny felhaszn�l�s�ra. A beadott feladatban nem szabad
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


