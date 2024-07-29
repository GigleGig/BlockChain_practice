#pragma once
#ifndef NETWORK_H
#define NETWORK_H

#include <unordered_map>
#include <vector>
#include <string>
#include "transaction.h"
#include "wallet.h"
#include "blockchain.h"

class Network {
public:
    void addNode(const std::string& nodeName);
    Wallet* getNode(const std::string& nodeName);
    void createTransaction(const std::string& sender, const std::string& receiver, double amount);
    void minePendingTransactions(Blockchain& blockchain);

private:
    std::unordered_map<std::string, Wallet*> nodes;
    std::vector<Transaction> pendingTransactions;
};

#endif
