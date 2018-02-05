/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #4, 2/4/18
 * 
 *  Fraction.h
 * 
 *  This class represents a fraction number, using 2 integers
 *  a/b. It has overloaded operators for calculations as well as
 *  helper methods for keeping itself valid and simplified. This 
 *  class is used by the FractionalComplex class to repesent 
 *  complex fractional numbers. Works as a standalone class as well.
 */

#ifndef H_Fraction_H
#define H_Fraction_H

#include <iostream>

class Fraction
{
    public:
        //~~~Constructors~~~//
        Fraction(int num = 0, int den = 1);
        Fraction(const Fraction& other);

        //~~~Getters/Setters~~~//
        void setNumer(int num); // checks negs/zeroes/reduce
        void setDenom(int den); // checks negs/zeroes/reduce
        int  getNumer() const;
        int  getDenom() const;

        //~~~General~~~//
        double toDouble() const;
         
        //~~~Operators~~~//
        Fraction operator+ (const Fraction &other);
        Fraction operator- (const Fraction &other);
        Fraction operator* (const Fraction &other);
        Fraction operator* (const int &num);
        Fraction operator++(int);
        Fraction operator++();
            bool operator==(const Fraction &other);
        friend std::ostream& operator<<(std::ostream &o, const Fraction &right);

    private:
        int numerator, denominator;
        
        void reduce();
        int  gcd(int x, int y);
        void checkNegatives();
        void checkZeroes();
        Fraction addFractions(int a, int b, int c, int d);
};

#endif