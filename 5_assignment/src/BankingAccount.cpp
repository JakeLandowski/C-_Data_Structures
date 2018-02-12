#include "BankingAccount.h"

#include <iostream>

BankingAccount::BankingAccount(std::string newID, double newBalance)
{
    if(!Utilities::isNumeric(newID))
    {
        std::cerr << "Given ID: " << newID << " must be numeric.";
    }

    id = newID;
    balance = newBalance;
    numWithdrawals = numDeposits = apr = 0;
}

std::string BankingAccount::getID() const
{
    return id;
}

void BankingAccount::deposit(double amt)
{
    balance += amt > 0 ? amt : 0;
}

double BankingAccount::withdraw(double amt)
{
    if(amt <= balance)
    {
        balance -= amt;
        numWithdrawals++;
        return amt;
    }

    std::cerr << "Cannot withdraw " << amt << "from " << balance;
}

void BankingAccount::monthlyCalc()
{
    balance += balance * (apr / 12);
}

void BankingAccount::endOfYear()
{
    numWithdrawals = numDeposits = 0;
}

    //  If other id is longer automatically larger
    //  Otherwise compare string digits if same length 
bool BankingAccount::operator<(const BankingAccount &other) const
{
    return id.length() < other.id.length() || id < other.id;
}