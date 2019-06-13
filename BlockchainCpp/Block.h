#ifndef BLOCK_H
#define BLOCK_H

#include<time.h>
#include <vector>

#include "Transaction.h"

using namespace std;

/**
 * 
 * @author anubhp
 * 
 * timestamp: date of creation of block.
 * transactions: list of transactions validated and added to the block.
 * nonce: random number to be calculated so that the hash of the the block has some features(here, hash will start from some number of zeros).
 * prevHash: contains the hash of the previous block in the blockchain.
 * hash: contains the hash of the block.
 *
 */

class Block {
    private:
        string prevHash;
        time_t timeStamp;
        vector<Transaction> transactions;
        string hash;
        long nonce;
    
    public:
        Block(vector<Transaction> transactions);
        string getPrevHash();
        void setPrevHash(string prevHash);
        time_t getTimeStamp();
        void setTimeStamp(time_t timeStamp);
        vector<Transaction> getTransactions();
        void setTransactions(vector<Transaction> transactions);
        string getHash();
        void setHash(string hash);
        long getNonce();
        void setNonce(long nonce);

        string timeToString(time_t timeStamp);
        string toString();


        string calculateHash();
        void mineBlock(int difficulty);
};

#endif