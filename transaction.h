#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
public:
    std::string sender;
    std::string receiver;
    double amount;

    Transaction(const std::string& sender, const std::string& receiver, double amount);
    std::string toString() const;
};

#endif
