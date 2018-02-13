#include "BankAccount.h"

#include <iostream>

BankAccount::BankAccount(std::string newID, double newBalance)
{
    if(!Utilities::isNumeric(newID))
    {
        std::cerr << "Given ID: " << newID << " must be numeric.";
    }

    id = newID;
    balance = newBalance;
    numWithdrawals = numDeposits = apr = 0;
}

std::string BankAccount::getID() const
{
    return id;
}

void BankAccount::deposit(double amt)
{
    if(amt > 0) 
    {
        numDeposits++;
        balance += amt;
    }
}

double BankAccount::withdraw(double amt)
{
    if(amt <= balance)
    {
        balance -= amt;
        numWithdrawals++;
        return amt;
    }
    
    std::cerr << "Cannot withdraw $" << amt << " from $" << balance << '.' << std::endl;
    
    return 0;
}

void BankAccount::monthlyCalc()
{
    balance += balance * ((apr / 12) / 100);
}

void BankAccount::endOfYear()
{
    numWithdrawals = numDeposits = 0;
}

    //  If other id is longer automatically larger
    //  Otherwise compare string digits if same length 
bool BankAccount::operator<(const BankAccount &other) const
{
    return id.length() < other.id.length() || id < other.id;
}