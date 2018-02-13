#include "SimpleSavings.h"
#include <iostream>

const double SimpleSavings::APR = 1;
const double SimpleSavings::EOY_FEE = 5;

SimpleSavings::SimpleSavings(std::string newID, double newBalance)
: BankAccount(newID, newBalance)
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
    std::cout << "Simple Account #" << id << " has $" 
              << std::fixed << balance << std::endl;
}
