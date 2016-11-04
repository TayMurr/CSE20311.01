//Taylor Murray for Part 1 of lab 8
//rational.cpp the class implementation file
#include<iostream>
#include<cmath>
using namespace std;
#include "rational.h"

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

//Returning a stream that has the numerator and the denominator
//The ostream has to be taken in by reference
ostream& operator<< (ostream &s, Rational &c){
  s << c.numer << "/" << c.denom;
  return s;
}

//The istream has to be taken in by reference so it can know that
//it read in a input since two things were taken out of the stream
istream& operator>> (istream &s, Rational &c){
  int x, y;
  cout << "Enter the numerator and denominator of you rational number: ";
  s >> x >> y;
  c.setRational(x, y);
  return s;
}

//simplifies using gcd algorithm
void Rational::simplify(){
  int a, b, t;
  a = numer;
  b = denom;
  //This is the iterative implementation of the euclideam algorithm
  while( b != 0){
    t = b;
    b = a % b;
    a = t;
  }
   setRational(numer / a, denom / a);
}
