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

template<class T>
struct DefaultComparator {
    int operator()(const T &a, const T &b) const { return (a < b) ? true : false; }
};

template<class T = int, class Comparator = DefaultComparator<T> >
class my_priqueue {
public:
    /** Bels� oszt�ly, amely az el�rehalad� iter�tort val�s�tja meg. */
    class iterator              //iterator inner class, a megfelelo metodusokat meg kell valositani
    {
        public:
            iterator() : _p(0) {}                                                   //default konstruktor iterator objektum letrehozasara
            iterator(const iterator &it) : _p(it._p) {}                             //copy konstruktor iterator objektum
            T& operator*() { return *_p; }                                          //dereferencia
            T* operator->() { return _p; }                                          
            iterator& operator++() { ++_p; return *this; }                          //prefix iterator lepteto muvelet
            iterator operator++(int) { iterator temp(*this); ++_p; return temp; }   //postfix iterator lepteto muvelet
            iterator& operator--() { --_p; return *this; }                          //prefix iterator lepteto muvelet
            iterator operator--(int) { iterator temp(*this); --_p; return temp; }   //postfix iterator lepteto muvelet
            bool operator==(const iterator &it) { return _p == it._p; }             //logikai egyenlo muvelet
            bool operator!=(const iterator &it) { return _p != it._p; }             //logikai nem egyenlo muvelet
        private:
            iterator(T* p) : _p(p) {}   //private konstruktor, ami megfelelo elemre allitja az iteratort
            T* _p;                      //az iterator altal mutatott elem
        friend class my_priqueue<T,Comparator>;   //Vector sablon friend definicioja, hogy hasznalhassuk a tipus parametereit iteratoron belul is
    };
    /** Bels� oszt�ly, amely a h�trafel�halad� iter�tort val�s�tja meg. */
    class reverse_iterator;

    /** A sablonp�ld�ny rendelkezik default konstruktorral. */
    my_priqueue() : _data(new T[0]), _size(0), _capacity(0) {};

    ~my_priqueue() { delete[] _data; }

    /** Elem besz�r�sa a priorit�si sorba a rendez�snek megfelel� helyre. */
    void push(const T &item) {     
        //ha nem tudunk t�bb elemet belerakni akkor megdupl�zzuk a t�mb m�ret�t
        //
        if (_size == _capacity) {
            int newcapacity = _capacity * 2 + 1;
            T *newdata = new T[newcapacity]; //nagyobb m�ret� t�mb l�trehoz�sa
            for (int i = 0; i < _capacity; i++) //eddigi elemek �tm�sol�sa
                newdata[i] = _data[i];
            delete[] _data;
            _data = newdata; //pointer be�ll�t�sa
            _capacity = newcapacity; //�j _capacity �rt�k be�ll�t�sa
        }
        //elem hozz�ad�sa �s _size �rt�k n�vel�se
        _data[_size++] = item;

        sort();
    }
    /** A priorit�si sor legels� elem�nek elt�vol�t�sa �s visszaad�sa. */
    T pop() {
        T first = _data[0];
        for (int i = 1; i<_size; i++){
            _data[i-1] = _data[i];
        }
        _size--;
        return first;
    };
    /** A priorit�si sorban lev� elemek sz�ma. */
    int size() { return _size; };
    /** A priorit�si sor elemeinek indexel�se (0-t�l size()-1 -ig). */
    const T& operator[](int index) const { return _data[index]; };
    /** El�rehalad� k�tir�ny� iter�tor t�pus a prisor elemeinek bej�r�s�ra. */
    class iterator;
    /** H�trafel� halad� k�tir�ny� iter�tor t�pus a prisor elemeinek bej�r�s�ra. */
    class reverse_iterator;
    /** El�rehalad� iter�tor a prisor legels� elem�re. */
    iterator begin() { return iterator(_data); }
    /** El�rehalad� iter�tor a prisor utols� ut�ni elem�re. */
    iterator end() { return iterator(_data + _size); }
    /** H�trafel� halad� iter�tor a prisor utols� elem�re. */
    reverse_iterator rbegin();
    /** H�trafel� halad� iter�tor a prisor els� el�tti elem�re. */
    reverse_iterator rend();
private: 
    T *_data;
    int _size;
    int _capacity;
    Comparator _comparator;

    void sort(){
        for (int i = 1; i<_size; i++)
        {
            for (int j = 0; j<_size - 1; j++)
            {
                if (_comparator(_data[j+1],_data[j]))
                {
                    T temp;
                    temp = _data[j];
                    _data[j] = _data[j + 1];
                    _data[j + 1] = temp;
                }
            }
        }
    }
};

// === MEGVAL�S�T�S V�GE ===