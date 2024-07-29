#include "transaction.h"
#include <sstream>

Transaction::Transaction(const std::string& sender, const std::string& receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {}

std::string Transaction::toString() const {
    std::stringstream ss;
    ss << sender << receiver << amount;
    return ss.str();
}
