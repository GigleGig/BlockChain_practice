#include "network.h"
#include <iostream>

void Network::addNode(const std::string& nodeName) {
    if (nodes.find(nodeName) == nodes.end()) {
        nodes[nodeName] = new Wallet(nodeName);
        std::cout << "Node " << nodeName << " added to the network." << std::endl;
    }
}

Wallet* Network::getNode(const std::string& nodeName) {
    return nodes[nodeName];
}

void Network::createTransaction(const std::string& sender, const std::string& receiver, double amount) {
    Wallet* senderWallet = getNode(sender);
    Wallet* receiverWallet = getNode(receiver);

    if (senderWallet && receiverWallet && senderWallet->debit(amount)) {
        receiverWallet->credit(amount);
        Transaction tx(sender, receiver, amount);
        pendingTransactions.push_back(tx);
        std::cout << "Transaction created: " << sender << " -> " << receiver << " : " << amount << std::endl;
    }
    else {
        std::cout << "Transaction failed." << std::endl;
    }
}

void Network::minePendingTransactions(Blockchain& blockchain) {
    blockchain.addBlock(pendingTransactions);
    pendingTransactions.clear();
}
