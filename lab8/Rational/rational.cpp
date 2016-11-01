//Taylor Murray rational.cpp the class implementation file
#include<iostream>
#include "rational.h"
using namespace std;
// Default contructor
Rational::Rational(){
  setRational(1, 1);
}

// Nondefault constructor
Rational::Rational(int n, int d) {
  setRational(n, d);
}

// deconstructor
Rational::~Rational(){
}

// Access Methods
int Rational::getNumer(){
  return numer;
}

int Rational::getDenom(){
  return denom;
}

void Rational::setRational(int n , int d){
  setNumer(n);
  setDenom(d);
}
void Rational::setNumer(int n){
  numer = n;
}

void Rational::setDenom(int d){
  denom = d;
}
// Utility Methods
void Rational::print(){
  cout << numer << "/" << denom << endl;
}

// adding using the overload operator
Rational Rational::operator+(Rational r){
  return Rational(r.denom * numer + denom * r.numer, denom * r.denom);
}

// subtracting using the - operator
Rational Rational::operator-(Rational r) {
  return Rational(r.denom * numer - denom * r.numer, denom * r.denom);
}

// multiplying using the * operator

Rational Rational::operator*(Rational r){
  return Rational(numer * r.numer, denom * r.denom);
}

// divide using / operator

Rational Rational::operator/(Rational r){
  return Rational(numer * r.denom, denom * r.numer);
}
