#ifndef H_CheckingAccount_H
#define H_CheckingAccount_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount
{
    public:
        CheckingAccount(std::string newID, double newBalance);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear();
        virtual void printStatus() const;

        static const double APR;
        static const double OVERDRAW_FEE;
        static const double MONTHLY_FEE;
        static const double ANNUAL_BASE_FEE;
};

#endif