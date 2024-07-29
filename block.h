#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>
#include "transaction.h"

class Block {
public:
    std::string previousHash;
    std::vector<Transaction> transactions;
    std::string hash;
    time_t timestamp;
    int nonce;

    Block(std::string previousHash, std::vector<Transaction> transactions);
    std::string calculateHash() const;
    void mineBlock(int difficulty);

private:
    static std::string calculateHash(const std::string& data);
};

#endif

