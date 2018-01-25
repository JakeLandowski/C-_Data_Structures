#ifndef H_PURSE_H
#define H_PURSE_H

#include <iostream>

class Purse 
{
    public:
        Purse(int c = 0, int s = 0, int g = 0);
        void addCopper(int c);
        void addSilver(int s);
        void addGold(int g);
        void print();
        Purse operator+(const int &c);
        Purse operator+(const Purse &right);
        friend std::ostream& operator<<(std::ostream& o, 
                                        const Purse &right);

    private:
        int copper, silver, gold;

        void copperToSilver();
        void silverToGold();
};


#endif