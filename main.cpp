#include "blockchain.h"
#include "network.h"
#include <iostream>

int main() {
    Blockchain myBlockchain(4);
    Network myNetwork;

    myNetwork.addNode("Alice");
    myNetwork.addNode("Bob");
    myNetwork.addNode("Charlie");

    myNetwork.getNode("Alice")->credit(1000);

    myNetwork.createTransaction("Alice", "Bob", 200);
    myNetwork.createTransaction("Bob", "Charlie", 150);

    myNetwork.minePendingTransactions(myBlockchain);

    myNetwork.createTransaction("Charlie", "Alice", 50);
    myNetwork.minePendingTransactions(myBlockchain);

    std::cout << "Blockchain valid: " << myBlockchain.isChainValid() << std::endl;

    myBlockchain.displayChain();

    std::cout << "Alice's balance: " << myNetwork.getNode("Alice")->getBalance() << std::endl;
    std::cout << "Bob's balance: " << myNetwork.getNode("Bob")->getBalance() << std::endl;
    std::cout << "Charlie's balance: " << myNetwork.getNode("Charlie")->getBalance() << std::endl;

    return 0;
}
