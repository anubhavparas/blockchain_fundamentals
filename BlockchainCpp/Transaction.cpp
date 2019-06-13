#include "Transaction.h"
#include "utils.h"

using namespace std;
using namespace utils;

Transaction::Transaction(string sender, string receiver, double amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
}

string Transaction::getSender() {
	return this->sender;
}
void Transaction::setSender(string sender) {
    this->sender = sender;
}
string Transaction::getReceiver() {
    return this->receiver;
}
void Transaction::setReceiver(string receiver) {
    this->receiver = receiver;
}
double Transaction::getAmount() {
    return this->amount;
}
void Transaction::setAmount(double amount) {
    this->amount = amount;
}

string Transaction::toString(){
    return "Transaction [sender=" + sender + ", receiver=" + receiver + ", amount=" + to_String(amount) + "]";
}