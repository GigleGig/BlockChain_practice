#pragma once
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <vector>
#include "block.h"

class Blockchain {
public:
    Blockchain(int difficulty);
    void addBlock(std::vector<Transaction> transactions);
    bool isChainValid() const;
    void displayChain() const;

private:
    std::vector<Block> chain;
    int difficulty;
};

#endif
