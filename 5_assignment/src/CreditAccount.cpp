#include "CreditAccount.h"
#include <iostream>

const double CreditAccount::APR = 7;
const double CreditAccount::CLOSED_THRESHOLD = 10000;
const double CreditAccount::EOY_FEE = 25;

CreditAccount::CreditAccount(std::string newID, double newBalance)
: BankAccount(newID, newBalance)
{
    apr = APR;
    lateStatus = 0;
}

void CreditAccount::deposit(double amt)
{
    if(balance < 0)  BankAccount::deposit(amt);
    if(balance >= 0) lateStatus = 0;
}

double CreditAccount::withdraw(double amt)
{
    if(!closed && lateStatus < 2)
    {
        numWithdrawals++;
        balance -= amt;
        return amt;
    }

    return 0;
}

void CreditAccount::monthlyCalc()
{
    if(balance < 0) 
    {
        lateStatus++;
        BankAccount::monthlyCalc();
    }
}

void CreditAccount::endOfYear()
{
    closed = balance >= CLOSED_THRESHOLD;
    balance -= EOY_FEE;
}

void CreditAccount::printStatus() const
{
    std::cout.precision(2);
    std::cout << "Credit Account #" << id 
              << (balance <= 0 ? " owes " : " is overpaid by ") 
              << "$" << std::fixed << (balance < 0 ? -balance : balance) 
              << (closed ? " and is currently closed." : ".") 
              << std::endl;
}