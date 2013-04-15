#include <iostream>
#include "RationalNumber.h"
#include <stdexcept>
using namespace std;

//constructor prevents a negative or zero deonominator
RationalNumber::RationalNumber(int num, int den)
{
  //prevent a zero or negative denominator
  if (den <=0)
    throw invalid_argument("Denominator must be greater than 0!");
  else
  {
    //find the greatest common  factor
    int divisor=gcd(num,den);
    
    //set the simplified numerator and denominator
    numerator = num/divisor;
    denominator = den/divisor;
  }
}

//overloaded + operator allows addition of rational numbers
RationalNumber RationalNumber::operator+(const RationalNumber &right)
{
  RationalNumber temp = *this;

  //cross multiply and add denominators
  int num = (temp.numerator * right.denominator) + (right.numerator * temp.denominator);
  
  //multiply numerators
  int den = (temp.denominator * right.denominator);
  
  //find gcd and simplify
  int divisor = gcd(num,den);

  if(divisor==0)
    throw invalid_argument("GCD can not be 0!");
  else
    {
      temp.numerator = num/divisor;
      temp.denominator = den/divisor;
    }

  return temp;
}

//overloaded - operator allows subtraction of rational numbers
RationalNumber RationalNumber::operator-(const RationalNumber &right)
{
  RationalNumber temp = *this;
  
  //cross multiply and subtract denominators
  int num = (temp.numerator * right.denominator) - (right.numerator * temp.denominator);
  
  //multiply numerators
  int den = (temp.denominator * right.denominator);
  
  //find gcd and simplify
  int divisor = gcd(num,den);

  //can't have a negative divisor
  if(divisor<0)
    divisor=divisor*-1;

  if(divisor==0)
    throw invalid_argument("GCD can not be 0!");
  else
    {
      temp.numerator = num/divisor;
      temp.denominator = den/divisor;
    }
  
  return temp;
}

//overloaded * operator allows multiplication of rational numbers
RationalNumber RationalNumber::operator*(const RationalNumber &right)
{
  RationalNumber temp = *this;

  //multiply numerators
  int num = temp.numerator * right.numerator;

  //multiply denomoninators
  int den = (temp.denominator * right.denominator);

  //find gcd and simplify
  int divisor = gcd(num,den);

  if(divisor==0)
    throw invalid_argument("GCD can not be 0!");
  else
    {
      temp.numerator = num/divisor;
      temp.denominator = den/divisor;
    }

  return temp;
}

//overloaded / operator allows division of rational numbers
RationalNumber RationalNumber::operator/(const RationalNumber &right)
{
  RationalNumber temp = *this;

  //cross multiply by reciprocal of right
  int num = temp.numerator * right.denominator;

  //cross multiply by reciprocal of right
  int den = (temp.denominator * right.numerator);

  //find gcd and simplify
  int divisor = gcd(num,den);

  if(divisor==0)
    throw invalid_argument("GCD can not be 0!");
  else
    {
      temp.numerator = num/divisor;
      temp.denominator = den/divisor;
    }

  return temp;
}

//overloaded > operator
bool RationalNumber::operator>(RationalNumber &right) const
{
  RationalNumber temp = *this;
  RationalNumber difference = temp-right;
  if(difference.numerator > 0)
    return true;
  else
    return false;
}

//overloaded >= operator
bool RationalNumber::operator>=(RationalNumber &right) const
{
  RationalNumber temp = *this;
  RationalNumber difference = temp-right;
  if(difference.numerator >= 0)
    return true;
  else
    return false;
}

//overloaded < operator
bool RationalNumber::operator<(RationalNumber &right) const
{
  RationalNumber temp = *this;
  RationalNumber difference = temp-right;
  if(difference.numerator < 0)
    return true;
  else
    return false;
}

//overloaded <= operator
bool RationalNumber::operator<=(RationalNumber &right) const
{
  RationalNumber temp = *this;
  RationalNumber difference = temp-right;
  if(difference.numerator <= 0)
    return true;
  else
    return false;
}

//overloaded == operator
bool RationalNumber::operator==(RationalNumber &right) const
{
  RationalNumber temp = *this;
  RationalNumber difference = temp-right;
  if(difference.numerator == 0)
    return true;
  else
    return false;
}

//overloaded != operator
bool RationalNumber::operator!=(RationalNumber &right) const
{
  RationalNumber temp = *this;
  RationalNumber difference = temp-right;
  if(difference.numerator != 0)
    return true;
  else
    return false;
}

// private helper function to find the greates common factor
int RationalNumber::gcd(int num, int den)
{
  if(den == 0)
    return num;
  else
    return gcd(den, num % den);
}

//overloaded stream insertion operator
ostream &operator<<(ostream &output, const RationalNumber &n)
{
  if(n.denominator !=1 )
    output << n.numerator << "/" << n.denominator;
  else
    output << n.numerator;
  
  //allow cascading by returning a reference to the stream
  return output;
}
