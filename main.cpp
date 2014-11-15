#include "feladat.cpp"
#include <iostream>

using namespace std;

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
    bool operator()(const int &a, const int &b){
        if (a>b){
            return true;
        } else {
            return false;
        }
    };
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
    q1.push(4);
    q1.push(100);
/*    
    my_priqueue<int, comparator> q2;
    q2.push(31);
    q2.push(1977);
*/

    my_priqueue<int>::iterator it;
    for (it = q1.begin(); it != q1.end(); ++it)
    cout << *it << " " << endl;
    
    return 0;
}

