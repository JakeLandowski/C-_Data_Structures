#include "CheckingAccount.h"
#include <iostream>

const double CheckingAccount::APR = 0;
const double CheckingAccount::OVERDRAW_FEE = 15;
const double CheckingAccount::MONTHLY_FEE  = 5;
const double CheckingAccount::ANNUAL_BASE_FEE = 5;

CheckingAccount::CheckingAccount(std::string newID, double newBalance)
: BankAccount(newID, newBalance)
{
    apr = APR;
}

double CheckingAccount::withdraw(double amt)
{   
    double returnAmt = BankAccount::withdraw(amt);

    if(returnAmt <= 0) balance -= OVERDRAW_FEE;
    
    return returnAmt;
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