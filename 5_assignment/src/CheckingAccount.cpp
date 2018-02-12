#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(std::string newID, double newBalance)
: BankingAccount(newID, newBalance)
{
    apr = APR;
}

double CheckingAccount::withdraw(double amt)
{   
    if(amt > balance) 
    {
        balance -= OVERDRAW_FEE;
        return 0;
    }
    else
    {
        balance -= amt;
        return amt;
    }
}

void CheckingAccount::monthlyCalc()
{
    if(balance < 0) balance -= MONTHLY_FEE;
}

void CheckingAccount::endOfYear()
{
    balance -= ANNUAL_BASE_FEE + (numWithdrawals * 0.1);
}

void CheckingAccount::printStatus() const
{
    std::cout.precision(2);
    std::cout << "Checking Account #" << id << " has $"
              << std::fixed << balance << " with " << numWithdrawals
              << " withdrawals this year." << std::endl; 
}