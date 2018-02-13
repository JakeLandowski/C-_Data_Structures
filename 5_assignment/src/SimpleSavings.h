#ifndef H_SimpleSavings_H
#define H_SimpleSavings_H

#include "BankAccount.h"

class SimpleSavings : public BankAccount
{
    public:
        SimpleSavings(std::string newID, double newBalance);
        virtual void endOfYear();
        virtual void printStatus() const;

        static const double APR;
        static const double EOY_FEE;
};

#endif