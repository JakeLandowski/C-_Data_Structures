/**
 *  Jacob Landowski, CS132, Winter 2667, Section A
 *  Assignment #5, 2/13/18
 * 
 *  SimpleSavings.h
 * 
 *  Class that extends from BankAccount.h.
 *  Has normal account functions but with 
 *  interest and annual fees.
 */

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