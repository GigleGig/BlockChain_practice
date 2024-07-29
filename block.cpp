#include "block.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <iostream>

Block::Block(std::string previousHash, std::vector<Transaction> transactions)
    : previousHash(previousHash), transactions(transactions), timestamp(std::time(nullptr)), nonce(0) {
    hash = calculateHash();
}

std::string Block::calculateHash() const {
    std::stringstream ss;
    ss << previousHash << timestamp << nonce;
    for (const auto& transaction : transactions) {
        ss << transaction.toString();
    }
    return calculateHash(ss.str());
}

std::string Block::calculateHash(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    EVP_MD_CTX* context = EVP_MD_CTX_new();

    if (context == nullptr) {
        throw std::runtime_error("Failed to create OpenSSL context");
    }

    if (EVP_DigestInit_ex(context, EVP_sha256(), nullptr) != 1 ||
        EVP_DigestUpdate(context, data.c_str(), data.size()) != 1 ||
        EVP_DigestFinal_ex(context, hash, nullptr) != 1) {
        EVP_MD_CTX_free(context);
        throw std::runtime_error("Failed to compute SHA-256 hash");
    }

    EVP_MD_CTX_free(context);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

void Block::mineBlock(int difficulty) {
    std::string target(difficulty, '0');
    while (hash.substr(0, difficulty) != target) {
        nonce++;
        hash = calculateHash();
    }
    std::cout << "Block mined: " << hash << std::endl;
}
