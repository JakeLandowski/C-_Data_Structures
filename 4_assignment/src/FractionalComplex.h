/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #4, 2/4/18
 * 
 *  FractionalComplex.h
 * 
 *  This class represents 2 fractions in the form of (a/b) + (c/d)i
 *  with overloaded operators for calculating FractionalComplex objects.
 *  It uses the Fraction class to abstract most of the calculations.
 */

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
        void  printme() const;
        double length() const;

        //~~~Operators~~~//
        FractionalComplex operator+ (const FractionalComplex &other);
        FractionalComplex operator- (const FractionalComplex &other);
        FractionalComplex operator* (const FractionalComplex &other);
        FractionalComplex operator* (const int &num);
        FractionalComplex operator++(int);
        FractionalComplex operator++();
                     bool operator==(const FractionalComplex &other);
                     bool operator< (const FractionalComplex &other);
                     bool operator> (const FractionalComplex &other);
        friend std::ostream& operator<<(std::ostream &o, const FractionalComplex &right);

    private:
        Fraction real, imaginary;
};

#endif