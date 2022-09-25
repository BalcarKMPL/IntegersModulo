#include <iostream>
#include "IntMod.h"
using namespace std;

int main() {
    int mod = 6;
    cout << mod << endl;
    for (int ind1 = -1; ind1 < mod; ++ind1) {
        for (int ind2 = -1; ind2 < mod; ++ind2) {
            IntMod i(mod,ind1);
            IntMod j(mod,ind2);
            if (ind1 == -1 && ind2 == -1)
            {
                cout << "+";
            }
            else if (ind1 == -1)
            {
                cout << j;
            }
            else if (ind2 == -1)
            {
                cout << i;
            }
            else
            {
                cout << i + j;
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    for (int ind1 = -1; ind1 < mod; ++ind1) {
        for (int ind2 = -1; ind2 < mod; ++ind2) {
            IntMod i(mod,ind1);
            IntMod j(mod,ind2);
            if (ind1 == -1 && ind2 == -1)
            {
                cout << "*";
            }
            else if (ind1 == -1)
            {
                cout << j;
            }
            else if (ind2 == -1)
            {
                cout << i;
            }
            else
            {
                cout << i * j;
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
    for (int ind1 = -1; ind1 < mod; ++ind1) {
        for (int ind2 = -1; ind2 < mod; ++ind2) {
            IntMod i(mod,ind1);
            IntMod j(mod,ind2);
            if (ind1 == -1 && ind2 == -1)
            {
                cout << "-";
            }
            else if (ind1 == -1)
            {
                cout << j;
            }
            else if (ind2 == -1)
            {
                cout << i;
            }
            else
            {
                cout << i - j;
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
