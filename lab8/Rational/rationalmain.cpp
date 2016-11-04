// Taylor Murray Lab 7 Part 1 Simple driver for testing
#include <iostream>
using namespace std;
#include "rational.h"

int main()
{
  Rational a(5,6), b(3,7), c, s, d, e;

  cout << "a is: " << a << endl;
  cout << "b is: " << b << endl;
  cout << "c, s, and d are: " << c << " " << s << " " << d << endl;
  c = a + b;
  cout << "a + b: " << c << endl;
  s = a - b;
  cout << "a - b: " << s << endl;
  d = a * b;
  cout << "a * b: " << d << endl;
  d = a / b;
  cout << "a / b: " << d << endl;

  cin >> b;
  cout << "You rational number is: " << b << endl;
  b.simplify();
  cout << "b simplififed is: " << b << endl;
  return 0;
}
