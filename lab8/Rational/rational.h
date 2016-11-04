//Taylor Murray Part 1
// rational.h
// Now we are including overloading operators for the input and output

class Rational {
  // friend gives right to acces private members of class
  friend ostream& operator<< (ostream &, Rational &);
  friend istream& operator>> (istream &, Rational &);

  public:
    Rational();
    Rational(int, int);
    ~Rational();
    int getNumer();
    int getDenom();
    void setRational(int, int);
    void setDenom(int);
    void setNumer(int);
    void print();
    void simplify();

    //overload operators
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);

  private:
    int numer;
    int denom;
};
