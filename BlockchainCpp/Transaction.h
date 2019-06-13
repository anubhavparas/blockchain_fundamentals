#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<string>
using namespace std;

/**
 * 
 * @author anubhp
 * 
 * sender: address of the sender.
 * receiver: address of the receiver.
 * amount: amount/number of money/coins transferred.
 *
 */


class Transaction {
    private:
        string sender;
        string receiver;
        double amount;
    public:
        Transaction(string sender, string receiver, double amount);
        string getSender();
        void setSender(string sender);
        string getReceiver();
        void setReceiver(string receiver);
        double getAmount();
        void setAmount(double amount);
        string toString();
};

#endif