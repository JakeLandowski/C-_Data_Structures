#include "Fraction.h"

  //=====================================================//
 //                   CONSTRUCTORS                      //
//=====================================================//

    // Initializer list so reduce() calls in setters don't break
    // from uninitialized ints
Fraction::Fraction(int num, int den)
: numerator(1), denominator(1) 
{
    setNumer(num);
    setDenom(den);
}
    
Fraction::Fraction(const Fraction& other)
: numerator(1), denominator(1)
{
    setNumer(other.numerator);
    setDenom(other.denominator);
}

  //=====================================================//
 //                  PUBLIC METHODS                     //
//=====================================================//

double Fraction::toDouble() const
{
    return (double) numerator / denominator;
}

  //=====================================================//
 //                 GETTERS / SETTERS                   //
//=====================================================//

void Fraction::setNumer(int num)
{
     numerator = num; 
     checkZeroes();
     checkNegatives(); 
     reduce(); 
}

void Fraction::setDenom(int den)
{ 
    denominator = den; 
    checkZeroes();
    checkNegatives(); 
    reduce(); 
}

int Fraction::getNumer() const { return numerator; }
int Fraction::getDenom() const { return denominator; }

  //=====================================================//
 //                     OPERATORS                       //
//=====================================================//

Fraction Fraction::operator+(const Fraction &other)
{
    return addFractions
    (
        numerator, 
        denominator,
        other.numerator, 
        other.denominator
    );
}

Fraction Fraction::operator-(const Fraction &other)
{
    //  flip other.numerator to reuse addFractions method
    return addFractions
    (
        numerator, 
        denominator,
        -other.numerator, 
        other.denominator
    );
}

Fraction Fraction::operator*(const Fraction &other)
{
    Fraction result
    (
          numerator * other.numerator,
        denominator * other.denominator
    );

    return result;
}

bool Fraction::operator==(const Fraction &other)
{
    return   numerator == other.numerator &&
           denominator == other.denominator;
}

std::ostream& operator<<(std::ostream &o, const Fraction &right)
{
    o << '(' << right.numerator << '/' << right.denominator << ')';
    return o;   
}


  //=====================================================//
 //                  PRIVATE METHODS                    //
//=====================================================//

/**
 *  If denominators same, just add numerators
 *  Else cross multiply
 *  Create new fraction and return it 
 */
Fraction Fraction::addFractions(int a, int b, int c, int d)
{
    if(b == d) a += c;
    else 
    {
        a *= d;
        a += b * c;
        b *= d;
    } 

    // this checks zeroes/negs/reduction already
    Fraction result(a, b);

    return result;
}

/**
 *  Euclid's algorithm to find GCD between x and y
 *  Set larger number to the difference until both are equal
 *  Return that number which is the GCD
 */
int Fraction::gcd(int x, int y)
{
    if(x == 0 || y == 0) return 1;

    if(x < 0) x *= -1;  // use absolute value
    if(y < 0) y *= -1;

    while(x != y)
    {
             if(x > y) x -= y;
        else if(y > x) y -= x;
    }

    return x;
}

/**
 *  Grabs the GCD of each fraction and will reduce 
 *  them by that GCD if its greater than 1, which
 *  means they can be reduced.
 */
void Fraction::reduce()
{
    int GCD = gcd(numerator, denominator);

    if(GCD > 1)
    {
        numerator   /= GCD;
        denominator /= GCD;
    }
}

/**
 *  If denominator negative, flip both numbers
 */ 
void Fraction::checkNegatives()
{
    if(denominator < 0)
    {
        numerator   *= -1;
        denominator *= -1;
    } 
}

/**
 *  If denominator/numerator is 0, set numer = 0, set denom = 1 
 */ 
void Fraction::checkZeroes()
{
    if(denominator == 0 || numerator == 0)
    {
        numerator   = 0;
        denominator = 1;
    }
}