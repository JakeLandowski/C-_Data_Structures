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

FractionalComplex FractionalComplex::operator*(const FractionalComplex &other)
{
    FractionalComplex first
    (
        real * other.real,
        real * other.imaginary
    );

    // This one swaps fractions and flips sign
    // due to expanding
    FractionalComplex second
    (
        (imaginary * other.imaginary) * -1,
        imaginary * other.real
    );

    return first + second;    
}

FractionalComplex FractionalComplex::operator*(const int &num)
{
    FractionalComplex result
    (
             real * num,
        imaginary * num
    );

    return result;
}

//  POST
FractionalComplex FractionalComplex::operator++(int)
{
    FractionalComplex old(real, imaginary);

    real++;
    imaginary++;

    return old;
}

//  PRE
FractionalComplex FractionalComplex::operator++()
{
    real++;
    imaginary++;

    return *this;
}

FractionalComplex FractionalComplex::operator*(const FractionalComplex &other)
{
    FractionalComplex first
    (
        real * other.real,
        real * other.imaginary
    );

    // This one swaps fractions and flips sign
    // due to expanding
    FractionalComplex second
    (
        (imaginary * other.imaginary) * -1,
        imaginary * other.real
    );
    
    return first + second;    
}

FractionalComplex FractionalComplex::operator*(const int &num)
{
    FractionalComplex result
    (
             real * num,
        imaginary * num
    );

    return result;
}

//  POST
FractionalComplex FractionalComplex::operator++(int)
{
    FractionalComplex old(real, imaginary);

    real++;
    imaginary++;

    return old;
}

//  PRE
FractionalComplex FractionalComplex::operator++()
{
    real++;
    imaginary++;

    return *this;
}

bool FractionalComplex::operator==(const FractionalComplex &other)
{  
    return      real == other.real && 
           imaginary == other.imaginary;
}

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
    o << '[' << right.real << " + " << right.imaginary << "i]";
    return o;   
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