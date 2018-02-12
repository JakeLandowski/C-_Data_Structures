#include "SimpleSavings.h"
#include <iostream>


SimpleSavings::SimpleSavings(std::string newID, double newBalance)
: BankingAccount(newID, newBalance)
{
    apr = APR;
}

void SimpleSavings::endOfYear()
{
    balance -= EOY_FEE;
}

void SimpleSavings::printStatus() const
{
    std::cout.precision(2);
    std::cout << "Simple Account #" << id << "has $" << std::fixed << balance << std::endl;
}
