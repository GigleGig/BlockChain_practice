#pragma once
#ifndef WALLET_H
#define WALLET_H

#include <string>

class Wallet {
public:
    Wallet(const std::string& owner);
    void credit(double amount);
    bool debit(double amount);
    double getBalance() const;
    std::string getOwner() const;

private:
    std::string owner;
    double balance;
};

#endif
