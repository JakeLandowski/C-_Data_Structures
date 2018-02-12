#ifndef H_AdvancedSavings_H
#define H_AdvancedSavings_H

#include "BankingAccount.h"

class AdvancedSavings : public BankingAccount
{
    public:
        AdvancedSavings(std::string newID, double newBalance);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear() = 0;
        virtual void printStatus() const = 0;
    
        static const double BONUS_APR_THRESHOLD = 10000;
        static const double NORMAL_APR = 2;
        static const double BONUS_APR  = 3;
        static const int    BONUS_EOY_THRESHOLD = 0;
        static const double NORMAL_EOY_FEE = 10;
        static const double BONUS_EOY_FEE  = 5;
};

#endif