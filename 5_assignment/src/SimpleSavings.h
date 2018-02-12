#ifndef H_SimpleSavings_H
#define H_SimpleSavings_H

#include "BankingAccount.h"

class SimpleSavings : public BankingAccount
{
    public:
        SimpleSavings(std::string newID, double newBalance);
        virtual void endOfYear() = 0;
        virtual void printStatus() const = 0;

        static const double APR = 1;
        static const double EOY_FEE = 5;
};

#endif