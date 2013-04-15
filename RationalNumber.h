#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
using namespace std;

//stores a rational number in the form numerator/denominator
class RationalNumber
{
  //overloaded stream insertion operator prints a rational number
  friend ostream &operator<<(ostream &, const RationalNumber &);
 public:
  //constructor
  RationalNumber(int, int);
  
  //overloaded operations +, -, * and /
  RationalNumber operator+(const RationalNumber &);
  RationalNumber operator-(const RationalNumber &);
  RationalNumber operator*(const RationalNumber &);
  RationalNumber operator/(const RationalNumber &);
 
  //overloaded relational operators
  bool operator>(RationalNumber &) const;
  bool operator>=(RationalNumber &) const;
  bool operator<(RationalNumber &) const;
  bool operator<=(RationalNumber &) const;
  bool operator==(RationalNumber &) const;
  bool operator!=(RationalNumber &) const;
 private:
  int numerator;
  int denominator;
  //helper function to find greatest common divisor
  int gcd(int,int);
};

#endif
