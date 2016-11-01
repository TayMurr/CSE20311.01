// rational.h
// Now we are including overloading operators

class Rational {
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

    //overload operators
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
    /*Rational operator*>>(Rational);
    Rational operator*<<(Rational);*/
  private:
    int numer;
    int denom;
};
