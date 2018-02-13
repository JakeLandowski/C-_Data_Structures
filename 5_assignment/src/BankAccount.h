#ifndef H_BankAccount_H
#define H_BankAccount_H

#include "Utilities.h" // Inlcudes <string> <vector>

class BankAccount
{
    public:
        BankAccount(std::string newID, double newBalance);
        std::string getID() const;
        virtual void deposit(double amt);
        virtual double withdraw(double amt);
        virtual void monthlyCalc();
        virtual void endOfYear();
        virtual void printStatus() const = 0;
        bool operator<(const BankAccount &other) const;

    protected:
        std::string id;
        double balance, apr;
        int numWithdrawals, numDeposits;
};

#endif