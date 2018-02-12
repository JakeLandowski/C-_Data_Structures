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