#ifndef H_FractionalComplex_H
#define H_FractionalComplex_H

#include "Fraction.h"

class FractionalComplex
{
    public:
        FractionalComplex(int a = 0, int c = 0);
        FractionalComplex(int a, int b, int c, int d);
        FractionalComplex(const Fraction &real, const Fraction &imaginary);
        void printme();
        FractionalComplex operator+(const FractionalComplex &other);
        friend std::ostream& operator<<(std::ostream &o, const FractionalComplex &right);

    private:
        Fraction real, imaginary;
};

#endif