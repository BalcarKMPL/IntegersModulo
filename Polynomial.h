//
// Created by mazur on 26.09.22.
//

#ifndef INTEGERSMODULO_POLYNOMIAL_H
#define INTEGERSMODULO_POLYNOMIAL_H
#include "IntMod.h"
#include <string>

struct Polynomial {
private:
    int _deg;
    int _mod;
    IntMod* _p;
public:
    Polynomial(int deg, int mod);
    Polynomial(int deg, IntMod* p);
    explicit Polynomial(IntMod p);
    string Print() const;
    IntMod GetElement(int i) const;
    friend Polynomial operator*(Polynomial a, int b);
    friend Polynomial operator*(Polynomial a, IntMod b);
    friend Polynomial operator*(int b, Polynomial a);
    friend Polynomial operator*(IntMod b, Polynomial a);
    friend Polynomial operator*(Polynomial a, Polynomial b);
    friend Polynomial operator+(Polynomial a, int b);
    friend Polynomial operator+(Polynomial a, IntMod b);
    friend Polynomial operator+(int b, Polynomial a);
    friend Polynomial operator+(IntMod b, Polynomial a);
    friend Polynomial operator+(Polynomial a, Polynomial b);
    friend Polynomial operator-(Polynomial a, int b);
    friend Polynomial operator-(Polynomial a, IntMod b);
    friend Polynomial operator-(int b, Polynomial a);
    friend Polynomial operator-(IntMod b, Polynomial a);
    friend Polynomial operator-(Polynomial a, Polynomial b);
};


#endif //INTEGERSMODULO_POLYNOMIAL_H
