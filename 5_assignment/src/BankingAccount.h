#ifndef H_BankingAccount_H
#define H_BankingAccount_H

#include "Utilities.h" // Inlcudes <string> <vector>

class BankingAccount
{
    public:
        BankingAccount(std::string newID, double newBalance);
        std::string getID() const;
        virtual void deposit(double amt);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear() = 0;
        virtual void printStatus() const = 0;
        bool operator<(const BankingAccount &other) const;

    protected:
        std::string id;
        double balance, apr;
        int numWithdrawals, numDeposits;
};

#endif