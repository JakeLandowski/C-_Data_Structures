#ifndef H_CreditAccount_H
#define H_CreditAccount_H

#include "BankAccount.h"

class CreditAccount : public BankAccount
{
    public:
        CreditAccount(std::string newID, double newBalance);
        virtual void deposit(double amt);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear();
        virtual void printStatus() const;

        static const double APR;
        static const double CLOSED_THRESHOLD;
        static const double EOY_FEE;

    private:
        int lateStatus;
        bool closed;
};

#endif