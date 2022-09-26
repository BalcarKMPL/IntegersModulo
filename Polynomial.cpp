//
// Created by mazur on 26.09.22.
//

#include "Polynomial.h"
#include "IntMod.h"
#include <string>
#include <stdlib.h>

Polynomial::Polynomial(int deg, int mod) {
    _deg = deg;
    _mod = mod;
    _p = (IntMod*)calloc(sizeof(IntMod),deg+1);
}

Polynomial::Polynomial(int deg, IntMod* p) {
    _deg = deg;
    _mod = p->GetMod();
    _p = p;
}

Polynomial::Polynomial(IntMod p) {
    _mod = p.GetMod();
    _p = (IntMod*)calloc(sizeof(IntMod),1);
    _deg = 0;
    *(_p) = p;
}

string Polynomial::Print() const {
    string s = "";

    for (int i = 0; i <= _deg; ++i) {
        if (*(_p + i) == 0) continue;
        s += (s==""?"":" + ");
        s += (string)(*(_p + i)) + "x" + to_string(i);
    }
    return s;
}

Polynomial operator*(const Polynomial a, const int b) {
    return a * IntMod(a._mod,b);
}

Polynomial operator*(const Polynomial a, const IntMod b) {
    return a * Polynomial(b);
}

Polynomial operator*(const Polynomial a, const Polynomial b) {
    IntMod* p = (IntMod*)calloc(sizeof(IntMod), 1 + a._deg + b._deg);
    for (int i = 0; i <= a._deg+b._deg; ++i) {
        *(p+i) = IntMod(a._mod);
    }
    for (int i = 0; i <= a._deg; ++i) {
        for (int j = 0; j <= b._deg; ++j) {
            *(p+i+j) += a.GetElement(i) * b.GetElement(j);
        }
    }

    return Polynomial(a._deg + b._deg, p);
}

IntMod Polynomial::GetElement(int i) const {
    if (i > _deg) throw 1;
    return *(_p + i);
}

Polynomial operator+(const Polynomial a, const int b) {
    return a + IntMod(a._mod,b);
}

Polynomial operator+(const Polynomial a, const IntMod b) {
    return a + Polynomial(b);
}

Polynomial operator+(const Polynomial a, const Polynomial b) {
    int deg = a._deg > b._deg ? a._deg : b._deg;
    IntMod* p = (IntMod*)calloc(sizeof(IntMod), deg);
    for (int i = 0; i <= deg; ++i) {
        *(p+i) = *(new IntMod(a._mod));
        if (i <= a._deg) *(p+i) += a.GetElement(i);
        if (i <= b._deg) *(p+i) += b.GetElement(i);
    }
    return Polynomial(deg, p);
}

Polynomial operator*(int b, Polynomial a) {
    return a * b;
}

Polynomial operator*(IntMod b, Polynomial a) {
    return a * b;
}

Polynomial operator+(int b, Polynomial a) {
    return a + b;
}

Polynomial operator+(IntMod b, Polynomial a) {
    return a + b;
}

Polynomial operator-(Polynomial a, int b) {
    return a + (-b);
}

Polynomial operator-(Polynomial a, IntMod b) {
    return a + (-b);
}

Polynomial operator-(int b, Polynomial a) {
    return (-1) * (a - b);
}

Polynomial operator-(IntMod b, Polynomial a) {
    return (-1) * (a - b);
}

Polynomial operator-(Polynomial a, Polynomial b) {
    return a + (-1*b);
}



