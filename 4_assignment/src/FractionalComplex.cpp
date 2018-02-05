/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #4, 2/4/18
 * 
 *  FractionalComplex.cpp
 * 
 *  Implemenations for the FractionalComplex class.
 */

#include "FractionalComplex.h"
#include <iostream>
#include <math.h>

using namespace std;

  //=====================================================//
 //                   CONSTRUCTORS                      //
//=====================================================//

FractionalComplex::FractionalComplex(int a, int c)
: real(a, 1), imaginary(c, 1) { }

FractionalComplex::FractionalComplex(int a, int b, int c, int d) 
: real(a, b), imaginary(c, d) { }

FractionalComplex::FractionalComplex(const Fraction &real, const Fraction &imaginary)
: real(real), imaginary(imaginary) { }

  //=====================================================//
 //                   PUBLIC METHODS                    //
//=====================================================//

void FractionalComplex::printme() const
{
    cout << "[" << real << " + " << imaginary << "i]" << endl;
}

double FractionalComplex::length() const
{
    return sqrt
    (
        pow(real.toDouble(), 2) 
        + 
        pow(imaginary.toDouble(), 2)
    );
}

  //=====================================================//
 //                     OPERATORS                       //
//=====================================================//

FractionalComplex FractionalComplex::operator+(const FractionalComplex &other)
{  
    //  Use (Fraction, Fraction) constructor to just add the real and imaginaries
    //  Fraction addition implemented in Fraction.cpp
    FractionalComplex result
    (
             real + other.real,
        imaginary + other.imaginary
    );

    return result;    
}

FractionalComplex FractionalComplex::operator-(const FractionalComplex &other)
{  
    //  Use (Fraction, Fraction) constructor to just add the real and imaginaries
    //  Fraction addition implemented in Fraction.cpp
    FractionalComplex result
    (
             real - other.real,
        imaginary - other.imaginary
    );

    return result;    
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

bool FractionalComplex::operator<(const FractionalComplex &other)
{  
    return length() < other.length();
}

bool FractionalComplex::operator>(const FractionalComplex &other)
{  
    return length() > other.length();
}

std::ostream& operator<<(std::ostream &o, const FractionalComplex &right)
{
    o << '[' << right.real << " + " << right.imaginary << "i]";
    return o;   
}

  //=====================================================//
 //                  PRIVATE METHODS                    //
//=====================================================//