#include "AdvancedSavings.h"
#include <iostream>

AdvancedSavings::AdvancedSavings(std::string newID, double newBalance)
: BankingAccount(newID, newBalance) 
{
    apr = NORMAL_APR;
}

double AdvancedSavings::withdraw(double amt)
{
    BankingAccount::withdraw(amt);
    balance -= numWithdrawals;
}

void AdvancedSavings::monthlyCalc()
{
    if(balance >= BONUS_APR_THRESHOLD) 
        apr = BONUS_APR;
    else 
        apr = NORMAL_APR;

    BankingAccount::monthlyCalc();
}

void AdvancedSavings::endOfYear()
{
    BankingAccount::endOfYear();
    balance -= (numWithdrawals <= BONUS_EOY_THRESHOLD) ? BONUS_EOY_FEE : NORMAL_EOY_FEE;
}

void AdvancedSavings::printStatus() const
{
    std::cout.precision(2);
    std::cout << "Advanced Account #" << id << " has $" << std::fixed << balance
              << " with " << numWithdrawals << " withdrawals this year." << std::endl;
}

