#ifndef H_FractionalComplex_H
#define H_FractionalComplex_H

#include "Fraction.h"

class FractionalComplex
{
    public:
        FractionalComplex(int a = 0, int c = 0);
        FractionalComplex(int a, int b, int c, int d);
        void printme();
        FractionalComplex operator+(const FractionalComplex &other);

    private:
        Fraction real, imaginary;
};

#endif