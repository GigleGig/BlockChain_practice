#include "blockchain.h"
#include <iostream>

Blockchain::Blockchain(int difficulty) : difficulty(difficulty) {
    std::vector<Transaction> genesisTransactions;
    genesisTransactions.push_back(Transaction("0", "0", 0));
    chain.emplace_back(Block("0", genesisTransactions));
    chain[0].mineBlock(difficulty);
}

void Blockchain::addBlock(std::vector<Transaction> transactions) {
    Block newBlock(chain.back().hash, transactions);
    newBlock.mineBlock(difficulty);
    chain.push_back(newBlock);
}

bool Blockchain::isChainValid() const {
    for (size_t i = 1; i < chain.size(); ++i) {
        const Block& currentBlock = chain[i];
        const Block& previousBlock = chain[i - 1];

        if (currentBlock.hash != currentBlock.calculateHash()) {
            return false;
        }

        if (currentBlock.previousHash != previousBlock.hash) {
            return false;
        }
    }
    return true;
}

void Blockchain::displayChain() const {
    for (const auto& block : chain) {
        std::cout << "Block hash: " << block.hash << std::endl;
        std::cout << "Previous hash: " << block.previousHash << std::endl;
        std::cout << "Timestamp: " << block.timestamp << std::endl;
        std::cout << "Nonce: " << block.nonce << std::endl;
        for (const auto& transaction : block.transactions) {
            std::cout << "Transaction: " << transaction.sender << " -> " << transaction.receiver << " : " << transaction.amount << std::endl;
        }
        std::cout << "-----------------------------------" << std::endl;
    }
}
