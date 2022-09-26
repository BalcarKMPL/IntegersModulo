//
// Created by mazur on 25.09.22.
//

using namespace std;
#include <iostream>
#include <string>

#ifndef INTEGERSMODULO_INTMOD_H
#define INTEGERSMODULO_INTMOD_H


struct IntMod {
private:
    int _val;
    int _mod;
public:
    IntMod(int mod);
    IntMod(int mod, int val);
    void SetVal(int val);
    int GetVal() const;
    int GetMod() const;
    static IntMod add(IntMod a, IntMod b);
    static IntMod add(IntMod a, int b);
    static IntMod add(int a, IntMod b);
    static IntMod diff(IntMod a, IntMod b);
    static IntMod diff(int a, IntMod b);
    static IntMod diff(IntMod a, int b);
    static IntMod mult(IntMod a, IntMod b);
    static IntMod mult(int a, IntMod b);
    static IntMod mult(IntMod a, int b);
    friend std::ostream& operator<<(std::ostream& out, IntMod a);
    friend std::istream& operator>>(std::istream& in, IntMod a);
    friend IntMod operator+(IntMod a, IntMod b);
    friend IntMod operator+(int a, IntMod b);
    friend IntMod operator+(IntMod a, int b);
    friend IntMod operator-(IntMod a, IntMod b);
    friend IntMod operator-(int a, IntMod b);
    friend IntMod operator-(IntMod a, int b);
    friend IntMod operator*(IntMod a, IntMod b);
    friend IntMod operator*(int a, IntMod b);
    friend IntMod operator*(IntMod a, int b);
    friend bool operator==(IntMod a, IntMod b);
    friend bool operator!=(IntMod a, IntMod b);
    friend bool operator==(IntMod a, int b);
    friend bool operator!=(IntMod a, int b);
    friend bool operator==(int a, IntMod b);
    friend bool operator!=(int a, IntMod b);
    IntMod& operator=(IntMod b);
    IntMod& operator=(int b);
    IntMod operator+=(IntMod b);
    IntMod operator+=(int b);
    IntMod operator-=(IntMod b);
    IntMod operator-=(int b);
    IntMod operator*=(IntMod b);
    IntMod operator*=(int b);
    IntMod operator++();
    IntMod operator--();
    IntMod operator++(int);
    IntMod operator--(int);
    IntMod operator+();
    IntMod operator-();
    operator string() const;
};



#endif //INTEGERSMODULO_INTMOD_H
