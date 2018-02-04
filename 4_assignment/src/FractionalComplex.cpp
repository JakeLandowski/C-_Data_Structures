#include <iostream>
#include "FractionalComplex.h"

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

void FractionalComplex::printme()
{
    cout << "[" << real << " + " << imaginary << "i]" << endl;
}

  //=====================================================//
 //                     OPERATORS                       //
//=====================================================//

FractionalComplex FractionalComplex::operator+(const FractionalComplex &other)
{
    FractionalComplex result;

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