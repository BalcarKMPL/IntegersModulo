//
// Created by mazur on 25.09.22.
//

#include "IntMod.h"
using namespace std;

IntMod::IntMod(int mod) {
    _mod = mod;
    _val = 0;
}

IntMod::IntMod(int mod, int val) {
    _mod = mod;
    SetVal(val);
}

int IntMod::GetVal() const {
    return _val;
}

void IntMod::SetVal(int val) {
    //Sprowadza dowolnie duże/małe val do rzędu v \in [0,2*_mod)
    int v = (val - (val / _mod - 1) * _mod) % _mod;
    _val = v;
}

IntMod IntMod::add(const IntMod a, const IntMod b) {
    if (a._mod != b._mod){
        throw a._mod * b._mod;
    }
    return IntMod(a._mod, a._val + b._val);
}

IntMod IntMod::add(const IntMod a, const int b) {
    return IntMod(a._mod, a._val + b);
}

IntMod IntMod::add(const int a, const IntMod b) {
    return IntMod(b._mod, a + b._val);
}

IntMod IntMod::diff(const IntMod a, const IntMod b) {
    if (a._mod != b._mod){
        throw a._mod * b._mod;
    }
    return IntMod(a._mod, a._val - b._val);
}

IntMod IntMod::diff(const int a, const IntMod b) {
    return IntMod(b._mod, a - b._val);
}

IntMod IntMod::diff(const IntMod a, const int b) {
    return IntMod(a._mod, a._val - b);
}

IntMod IntMod::mult(const IntMod a, const IntMod b) {
    if (a._mod != b._mod){
        throw a._mod * b._mod;
    }
    return IntMod(a._mod, a._val * b._val);
}

IntMod IntMod::mult(const int a, const IntMod b) {
    return IntMod(b._mod, a * b._val);
}

IntMod IntMod::mult(const IntMod a, const int b) {
    return IntMod(a._mod, a._val * b);
}

std::ostream& operator<<(std::ostream& out, const IntMod a){
    return out<<a.GetVal();
}

std::istream& operator>>(istream& in, IntMod a) {
    int buff;
    in >> buff;
    a.SetVal(buff);
    return in;
}

IntMod operator+(const IntMod a, const IntMod b){
    return IntMod::add(a, b);
}

IntMod operator+(const IntMod a, const int b){
    return IntMod::add(a, b);
}

IntMod operator+(const int a, const IntMod b){
    return IntMod::add(a, b);
}

IntMod operator-(const IntMod a, const IntMod b){
    return IntMod::diff(a, b);
}

IntMod operator-(const IntMod a, const int b){
    return IntMod::diff(a, b);
}

IntMod operator-(const int a, const IntMod b){
    return IntMod::diff(a, b);
}

IntMod operator*(const IntMod a, const IntMod b){
    return IntMod::mult(a, b);
}

IntMod operator*(const IntMod a, const int b){
    return IntMod::mult(a, b);
}

IntMod operator*(const int a, const IntMod b){
    return IntMod::mult(a, b);
}

IntMod& IntMod::operator=(const IntMod b) {
    if (_mod == 0) _mod = b.GetMod();
    if (_mod != b.GetMod() and _mod != 0){
        throw b.GetMod() * _mod;
    }
    (*this).SetVal(b.GetVal());
    return *this;
}

IntMod& IntMod::operator=(const int b) {
    (*this).SetVal(b);
    return *this;
}

IntMod IntMod::operator+=(const IntMod b) {
    *this = *this + b;
    return *this;
}

IntMod IntMod::operator+=(const int b) {
    *this = *this + b;
    return *this;
}

IntMod IntMod::operator-=(const IntMod b) {
    *this = *this - b;
    return *this;
}

IntMod IntMod::operator-=(const int b) {
    *this = *this - b;
    return *this;
}

IntMod IntMod::operator*=(const IntMod b) {
    *this = *this * b;
    return *this;
}

IntMod IntMod::operator*=(const int b) {
    *this = *this * b;
    return *this;
}

IntMod IntMod::operator++() {
    *this = *this + 1;
    return *this;
}

IntMod IntMod::operator--() {
    *this = *this - 1;
    return *this;
}

IntMod IntMod::operator++(int) {
    IntMod buff = *this;
    ++*this;
    return buff;
}

IntMod IntMod::operator--(int) {
    IntMod buff = *this;
    --*this;
    return buff;
}

bool operator==(const IntMod a, const IntMod b) {
    return (a.GetVal() == b.GetVal()) && (a.GetMod() == b.GetMod());
}

bool operator!=(const IntMod a, const IntMod b) {
    return !(a==b);
}

IntMod IntMod::operator+() {
    return IntMod((*this)._mod,(*this)._val);
}

IntMod IntMod::operator-() {
    return IntMod((*this)._mod,-(*this)._val);
}

int IntMod::GetMod() const {
    return _mod;
}

IntMod::operator string() const {
    return std::to_string(_val);
}

bool operator==(IntMod a, int b) {
    return a == IntMod(a.GetMod(), b);
}

bool operator!=(IntMod a, int b) {
    return !(a==b);
}

bool operator==(int a, IntMod b) {
    return b==a;
}

bool operator!=(int a, IntMod b) {
    return b!=a;
}

