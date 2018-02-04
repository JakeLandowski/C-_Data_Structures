#include <iostream>
#include "FractionalComplex.h"

using namespace std;

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

    // check negatives
    // check 0 denoms
    // reduce
}

void FractionalComplex::printme()
{
    cout << "[(" << a << '/' << b << ") + (" 
         << c << '/' << d << ")i]" << endl;
}