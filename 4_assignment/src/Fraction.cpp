#include "Fraction.h"

  //=====================================================//
 //                   CONSTRUCTORS                      //
//=====================================================//

Fraction::Fraction(int num, int den)
{
    numerator   = num;
    denominator = den;

    checkNegatives();
    checkZeroes();
    reduce();
}

  //=====================================================//
 //                  PUBLIC METHODS                     //
//=====================================================//

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
 *  them by that GCD if its not equal to 1, which
 *  means they can be reduced.
 */
void Fraction::reduce()
{
    int GCD = gcd(numerator, denominator);

    if(GCD != 1)
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
 *  If denominator is 0, set numer = 0, set denom = 1 
 */ 
void Fraction::checkZeroes()
{
    if(denominator == 0)
    {
        numerator   = 0;
        denominator = 1;
    }
}

  //=====================================================//
 //                     OPERATORS                       //
//=====================================================//


std::ostream& operator<<(std::ostream &o, const Fraction &right)
{
    o << '(' << right.numerator << '/' << right.denominator << ')';
    return o;   
}