#ifndef H_CheckingAccount_H
#define H_CheckingAccount_H

#include "BankingAccount.h"

class CheckingAccount : public BankingAccount
{
    public:
        CheckingAccount(std::string newID, double newBalance);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear() = 0;
        virtual void printStatus() const = 0;

        static const double OVERDRAW_FEE = 15;
        static const double APR = 0;
};

#endif