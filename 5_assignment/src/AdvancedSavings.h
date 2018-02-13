/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #5, 2/13/18
 * 
 *  CreditAccount.h
 * 
 *  Class that extends from BankAccount.
 *  Represents a special savings account
 *  with bonus interest and various fees
 */

#ifndef H_AdvancedSavings_H
#define H_AdvancedSavings_H

#include "BankAccount.h"

class AdvancedSavings : public BankAccount
{
    public:
        AdvancedSavings(std::string newID, double newBalance);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear();
        virtual void printStatus() const;
    
        static const double BONUS_APR_THRESHOLD;
        static const double NORMAL_APR;
        static const double BONUS_APR;
        static const int    BONUS_EOY_THRESHOLD;
        static const double NORMAL_EOY_FEE;
        static const double BONUS_EOY_FEE;
};

#endif