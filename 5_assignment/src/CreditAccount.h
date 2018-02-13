/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #5, 2/13/18
 * 
 *  CreditAccount.h
 * 
 *  Class that extends from BankAccount. 
 *  Represents a credit account by allowing 
 *  the account to go negative, accrues negative
 *  interest over time. Has a late and closed status
 *  that can prevent withdrawals. 
 */

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