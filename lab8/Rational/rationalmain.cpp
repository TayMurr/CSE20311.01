// Taylor Murray Lab 7 Part 1 Simple driver for testing
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s, d;
  cout << "*** display a and b ***\n";
  a.print();
  b.print();
  cout << "*** display c ***\n";
  c.print();  // recall that c was instantiated with the default constructor

  // 'mathematically' add a and b
  cout << "*** compute s as the math sum of a and b, and display s ***\n";
  d = a + b;
  d.print();

  cout << "*** difference of a and b ***\n";
  d = a - b;
  d.print();

  cout << "*** a multiplied by b ***\n";
  d = a * b;
  d.print();

  cout << "*** a divided by b ***\n";
  d = a / b;
  d.print();

  return 0;
}
