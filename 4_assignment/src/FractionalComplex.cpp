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
        pow(real.toDouble(), 2) + pow(imaginary.toDouble(), 2)
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
        real      + other.real,
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
        real      - other.real,
        imaginary - other.imaginary
    );

    return result;    
}

std::ostream& operator<<(std::ostream &o, const FractionalComplex &right)
{
    o << '[' << right.real << '/' << right.imaginary << "i]";
    return o;   
}

  //=====================================================//
 //                  PRIVATE METHODS                    //
//=====================================================//