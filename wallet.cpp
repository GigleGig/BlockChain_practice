#include "wallet.h"

Wallet::Wallet(const std::string& owner) : owner(owner), balance(0) {}

void Wallet::credit(double amount) {
    balance += amount;
}

bool Wallet::debit(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}

double Wallet::getBalance() const {
    return balance;
}

std::string Wallet::getOwner() const {
    return owner;
}
