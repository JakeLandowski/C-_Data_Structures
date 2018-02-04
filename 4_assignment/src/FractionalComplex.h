#ifndef H_FractionalComplex_H
#define H_FractionalComplex_H

#include "Fraction.h"

class FractionalComplex
{
    public:
        //~~~Constructors~~~//
        FractionalComplex(int a = 0, int c = 0);
        FractionalComplex(int a, int b, int c, int d);
        FractionalComplex(const Fraction &real, const Fraction &imaginary);
        
        //~~~General~~~//
        void printme() const;
        double length() const;

        //~~~Operators~~~//
        FractionalComplex operator+ (const FractionalComplex &other);
        FractionalComplex operator- (const FractionalComplex &other);
                     bool operator==(const FractionalComplex &other);
                     bool operator< (const FractionalComplex &other);
                     bool operator> (const FractionalComplex &other);
        friend std::ostream& operator<<(std::ostream &o, const FractionalComplex &right);

    private:
        Fraction real, imaginary;
};

#endif