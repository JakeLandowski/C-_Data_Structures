#ifndef H_FractionalComplex_H
#define H_FractionalComplex_H

class FractionalComplex
{
    public:
        FractionalComplex(int a = 0, int c = 0);
        FractionalComplex(int a, int b, int c, int d);
        void printme();
        

    private:
        int a, b, c, d;
        
        void reduce();
        void checkNegatives();
        void checkZeroes();
};

#endif