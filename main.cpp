#include <iostream>
#include "IntMod.h"
#include "Polynomial.h"
using namespace std;

int main() {
    int mod = 5000;
    IntMod arr1[] = {{mod},{mod},{mod}};
    IntMod arr2[] = {{mod},{mod},{mod}};
    int p1[] = {3,4,9};
    int p2[] = {0,4,3};
    for (int i = 0; i < 3; ++i) {
        arr1[i] = p1[i];
        cout << arr1[i] << " ";
    }
    cout<<endl<<endl;
    for (int i = 0; i < 3; ++i) {
        arr2[i] = p2[i];
        cout << arr2[i] << " ";
    }
    cout<<endl<<endl;
    Polynomial poly1(2, arr1), poly2(2, arr2);
    cout << poly1.Print() << endl;
    cout << poly2.Print() << endl;
    cout << (poly1 + poly2).Print() << endl;
    cout << (poly1 * poly2).Print() << endl;
    cout << (5 + poly2).Print() << endl;
    cout << (5 * poly2).Print() << endl;
    cout << (-1 * poly2).Print() << endl;

    return 0;
}
