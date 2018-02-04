#include <iostream>
#include "FractionalComplex.h"

using namespace std;

  //=====================================================//
 //                   CONSTRUCTORS                      //
//=====================================================//

FractionalComplex::FractionalComplex(int a, int c)
{
    this->a = a;
    this->b = 1;
    this->c = c;
    this->d = 1;
}

FractionalComplex::FractionalComplex(int a, int b, int c, int d) 
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;

    checkNegatives();
    checkZeroes();
    reduce();
}

  //=====================================================//
 //                   PUBLIC METHODS                    //
//=====================================================//

void FractionalComplex::printme()
{
    cout << "[(" << a << '/' << b << ") + (" 
         << c << '/' << d << ")i]" << endl;
}

  //=====================================================//
 //                     OPERATORS                       //
//=====================================================//

FractionalComplex FractionalComplex::operator+(const FractionalComplex &other)
{
    
}

  //=====================================================//
 //                  PRIVATE METHODS                    //
//=====================================================//

/**
 *  Euclid's algorithm to find GCD between x and y
 *  Set larger number to the difference until both are equal
 *  Return that number which is the GCD
*/
int FractionalComplex::gcd(int x, int y)
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
void FractionalComplex::reduce()
{
    int gcdAB = gcd(a, b);
    int gcdCD = gcd(c, d);

    if(gcdAB != 1)
    {
        a /= gcdAB;
        b /= gcdAB;
    }

    if(gcdCD != 1)
    {
        c /= gcdCD;
        d /= gcdCD;
    }  
}

/**
 *  If denominator negative, flip both numbers
 */ 
void FractionalComplex::checkNegatives()
{
    if(b < 0)
    {
        a *= -1;
        b *= -1;
    }

    if(d < 0)
    {
        c *= -1;
        d *= -1;
    } 
}

/**
 *  If denominator is 0, set numer = 0, set denom = 1 
 */ 
void FractionalComplex::checkZeroes()
{
    if(b == 0)
    {
        a = 0;
        b = 1;
    }

    if(d == 0)
    {
        c = 0;
        d = 1;
    }
}