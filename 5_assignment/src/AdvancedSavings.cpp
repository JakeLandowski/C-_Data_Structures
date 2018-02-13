#include "AdvancedSavings.h"
#include <iostream>

const double AdvancedSavings::BONUS_APR_THRESHOLD = 10000;
const double AdvancedSavings::NORMAL_APR = 2;
const double AdvancedSavings::BONUS_APR  = 3;
const int    AdvancedSavings::BONUS_EOY_THRESHOLD = 0;
const double AdvancedSavings::NORMAL_EOY_FEE = 10;
const double AdvancedSavings::BONUS_EOY_FEE  = 5;

AdvancedSavings::AdvancedSavings(std::string newID, double newBalance)
: BankAccount(newID, newBalance) 
{
    apr = NORMAL_APR;
}

double AdvancedSavings::withdraw(double amt)
{
    if(amt <= balance) balance -= numWithdrawals;
    double returnAmt = BankAccount::withdraw(amt);
    return returnAmt;
}

void AdvancedSavings::monthlyCalc()
{
    if(balance >= BONUS_APR_THRESHOLD) 
        apr = BONUS_APR;
    else 
        apr = NORMAL_APR;

    BankAccount::monthlyCalc(); // adds interest
}

void AdvancedSavings::endOfYear()
{
    BankAccount::endOfYear(); // reset numWithdrawals/numDeposits
    balance -= (numWithdrawals <= BONUS_EOY_THRESHOLD) ? BONUS_EOY_FEE : NORMAL_EOY_FEE;
}

void AdvancedSavings::printStatus() const
{
    std::cout.precision(2);
    std::cout << "Advanced Account #" << id << " has $" << std::fixed << balance
              << " with " << numWithdrawals << " withdrawals this year." << std::endl;
}

