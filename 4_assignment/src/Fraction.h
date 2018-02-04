#ifndef H_Fraction_H
#define H_Fraction_H

#include <iostream>

class Fraction
{
    public:
        Fraction(int num = 0, int den = 0);
        void reduce();
        int  gcd(int x, int y);
        void checkNegatives();
        void checkZeroes();
        
        friend std::ostream& operator<<(std::ostream &o, const Fraction &right);

    private:
        int numerator, denominator;
};

#endif