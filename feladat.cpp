/**
 * Alapértelmezett rendezési módszer
 */
template<class T>
struct DefaultComparator {
    /** 
     * Függvényhívás operátor felüldefiniálása, amely rendezést valósít meg. 
     * Visszatérési értéke igaz, ha a < b az alapértemezett "<" rendezési reláció szerint.
     */
    bool operator()(const T &a, const T &b) const { return (a < b) ? true : false; }
};

/**
 * @author Dobó László DOLSAAT.SZE
 * 
 * Feladatkiírás
 * 
 * A feladat olyan osztálysablon írása, amely prioritási sor adatszerkezetet 
 * valósít meg. A sorba beszúrható elemek típusát és a rendezést a sablon 
 * paraméterei határozzák meg. A prioritási sor az elemeit a rendezés szerint
 * növekvõ sorrendben tárolja, azaz legelöl a legkisebb elemet. A prioritási sor
 * méretét csak a rendelkezésre álló memória korlátozza, de a dinamikusan allokált
 * memória felszabadítását biztosítani kell!
 * 
 * A sablon legyen példányosítható egy (csak típus) és két (típus és rendezés) 
 * paraméterrel is. Amennyiben a rendezés paraméter nincs feltüntetve 
 * példányosításkor, úgy az alapértelmezett rendezés a < operátort
 * használja.
 * 
 * A prioritási sor adatszerkezetnek rendelkeznie kell elõre és hátrafelé haladó
 * iterátorokkal, és mindkettõnek kétirányúnak kell lennie. Azaz mindkét 
 * iterátortípusnak támogatnia kell a ++ és -- operátorokkal történõ léptetést is.
 * Az elõrefelé haladó iterátor a rendezés szerinti legkisebb elemtõl kell 
 * induljon, és a ++ mûvelet hatására a nagyobb elemek felé lépked (-- mûveletre
 * fordítva), míg a hátrafelé haladó iterátor (++ esetén) a legnagyobbtól halad a
 * legkisebb elem felé.
 * 
 * Az osztálysablon publikus interfésze (a sablon neve, a sablonparaméterezése, a 
 * publikus metódusainak szignatúrája) kötött, azaz legalább az alábbiaknak meg
 * kell felelnie (de amennyiben a feladatkiírás szükségessé teszi további publikus
 * metódusokkal, belsõ típusokkal bõvíthetõ, valamint az osztály törzsén kívül is 
 * szerepelhetnek további típusok, metódusok):
 * 
 * Változások az eredeti feladatkiíráshoz képest
 * 
 * 1. Pontosításra került, hogy az iterator és reverse_iterator osztályoknak a 
 *    my_priqueue osztály belsõ osztályainak kell lenni (nem lehetnek globálisak).
 * 2. Az elvárt publikus interfészbõl nemdefiniált mûködés miatt törlésre került a
 *    T& my_priqueue::operator[](int index);
 *    metódus .
 * 
 *
 * Az osztálysablon neve my_priqueue.
 * A sablon paraméterezése:
 *   - T: a sorba helyezhetõ elemek típusa
 *   - Comparator: típus, aminek példányai rendezést megvalósító 
 *                 függvényobjektumok
 */
template<class T = int, class Comparator = DefaultComparator<T> >
class my_priqueue {
public:
    /**
     * Belsõ osztály, amely az elõrehaladó iterátort valósítja meg. 
     */
    class iterator      
    {
        public:
            /** default konstruktor iterator objektum letrehozasara */
            iterator() : _p(0) {}                                                   
            /** copy konstruktor iterator objektum */
            iterator(const iterator &it) : _p(it._p) {}
            /** dereferencia */                             
            T& operator*() { return *_p; }                                          
            /** "nyíl" operátor */
            T * operator->() { return _p; }       
            /** prefix iterator lepteto muvelet */                                   
            iterator& operator++() { ++_p; return *this; }                         
            /** postfix iterator lepteto muvelet */
            iterator operator++(int) { iterator temp(*this); ++_p; return temp; } 
            /** prefix iterator lepteto muvelet */
            iterator& operator--() { --_p; return *this; }                         
            /** postfix iterator lepteto muvelet */
            iterator operator--(int) { iterator temp(*this); --_p; return temp; } 
            /** logikai egyenlo muvelet */
            bool operator==(const iterator &it) { return _p == it._p; }           
            /** logikai nem egyenlo muvelet */
            bool operator!=(const iterator &it) { return _p != it._p; }           
        private:
            /** private konstruktor, ami megfelelo elemre allitja az iteratort */
            iterator(T* p) : _p(p) {}  
            /** az iterator altal mutatott elem */
            T* _p;                     
        /** Prioritási sor sablon friend definicioja, hogy hasznalhassuk a tipus parametereit iteratoron belul is*/
        friend class my_priqueue<T,Comparator>; 
    };

    /**
     * Belsõ osztály, amely a hátrafele haladó iterátort valósítja meg. 
     */
    class reverse_iterator
    {
        public:
            /** default konstruktor reverse_iterator objektum letrehozasara */
            reverse_iterator() : _p(0) {}                                                   
            /** copy konstruktor reverse_iterator objektum */
            reverse_iterator(const reverse_iterator &it) : _p(it._p) {}
            /** dereferencia */                             
            T& operator*() { return *_p; }                                          
            /** "nyíl" operátor */
            T * operator->() { return _p; }       
            /** prefix reverse_iterator lepteto muvelet */                                   
            reverse_iterator& operator--() { ++_p; return *this; }                         
            /** postfix reverse_iterator lepteto muvelet */
            reverse_iterator operator--(int) { reverse_iterator temp(*this); ++_p; return temp; } 
            /** prefix reverse_iterator lepteto muvelet */
            reverse_iterator& operator++() { --_p; return *this; }                         
            /** postfix reverse_iterator lepteto muvelet */
            reverse_iterator operator++(int) { reverse_iterator temp(*this); --_p; return temp; } 
            /** logikai egyenlo muvelet */
            bool operator==(const reverse_iterator &it) { return _p == it._p; }           
            /** logikai nem egyenlo muvelet */
            bool operator!=(const reverse_iterator &it) { return _p != it._p; }           
        private:
            /** private konstruktor, ami megfelelo elemre allitja az reverse_iteratort */
            reverse_iterator(T* p) : _p(p) {}  
            /** az reverse_iterator altal mutatott elem */
            T* _p;                     
        /** Prioritási sor sablon friend definicioja, hogy hasznalhassuk a tipus parametereit reverse_iteratoron belul is*/
        friend class my_priqueue<T,Comparator>; 
    };

    /** A sablonpéldány rendelkezik default konstruktorral. */
    my_priqueue() : _data(new T[0]), _size(0), _capacity(0) {};

    /** A destruktor felszabadítja a memóriaterületet. */
    ~my_priqueue() { delete[] _data; }

    /** Elem beszúrása a prioritási sorba a rendezésnek megfelelõ helyre. */
    void push(const T &item) {     
        //ha nem tudunk több elemet belerakni akkor megduplázzuk a tömb méretét
        if (_size == _capacity) {
            int newcapacity = _capacity * 2 + 1;
            T *newdata = new T[newcapacity]; //nagyobb méretû tömb létrehozása
            for (int i = 0; i < _capacity; i++) //eddigi elemek átmásolása
                newdata[i] = _data[i];
            delete[] _data;
            _data = newdata; //pointer beállítása
            _capacity = newcapacity; //új _capacity érték beállítása
        }
        //elem hozzáadása és _size érték növelése
        _data[_size++] = item;
        //elemek rendezése
        sort();
    }

    /** A prioritási sor legelsõ elemének eltávolítása és visszaadása. */
    T pop() {
        T first = _data[0];
        for (int i = 1; i<_size; i++){
            _data[i-1] = _data[i];
        }
        _size--;
        return first;
    };

    /** A prioritási sorban levõ elemek száma. */
    int size() { return _size; };
    /** A prioritási sor elemeinek indexelése (0-tól size()-1 -ig). */
    const T& operator[](int index) const { return _data[index]; };
    /** Elõrehaladó kétirányú iterátor típus a prisor elemeinek bejárására. */
    class iterator;
    /** Hátrafelé haladó kétirányú iterátor típus a prisor elemeinek bejárására. */
    class reverse_iterator;
    /** Elõrehaladó iterátor a prisor legelsõ elemére. */
    iterator begin() { return iterator(_data); }
    /** Elõrehaladó iterátor a prisor utolsó utáni elemére. */
    iterator end() { return iterator(_data + _size); }
    /** Hátrafelé haladó iterátor a prisor utolsó elemére. */
    reverse_iterator rbegin() { return reverse_iterator(_data + _size - 1); }
    /** Hátrafelé haladó iterátor a prisor elsõ elõtti elemére. */
    reverse_iterator rend() { return reverse_iterator(_data - 1 ); }
private: 
    /** elemek tárolása a prioritási sorban */
    T *_data;
    /** a prioritási sorban lévő elemek száma */ 
    int _size;
    /** _data adattároló maximális kapacitása */
    int _capacity;
    /** Sablonpéldány a rendezésre */
    Comparator _comparator;

    /**
     * Rendezés végrehajtása comparator sablonpéldánnyal
     */
    void sort(){
        for (int j = _size-2; 0<=j; j--)
        {
            if (_comparator(_data[j+1],_data[j]))
            {
                T temp;
                temp = _data[j];
                _data[j] = _data[j+1];
                _data[j+1] = temp;
            }
        }
    }

};
