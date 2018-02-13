/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #5, 2/13/18
 * 
 *  CreditAccount.h
 * 
 *  Class that extends from BankAccount.
 *  Represents a normal checking account with
 *  and overdraw fee, no interest, and monthly
 *  and annual fees.
 */

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