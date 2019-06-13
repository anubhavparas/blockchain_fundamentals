#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"

using namespace std;

/**
 * 
 * @author anubhp
 * 
 * name: name of the blockchain.
 * chain: array of blocks.
 * difficulty: difficulty of the blockchain to validate the block (number of zeros at the start of the hash of every block).
 * pendingTransactions: list of pending/unconfirmed transactions
 * rewardForMining: reward/token amount/coins given to the miners for mining the block and adding a valid block in the blockchain.
 *
 */

class Blockchain {
    private:
        string name;
        vector<Block> chain;
        int difficulty;
        vector<Transaction> pendingTransactions;
        double rewardForMining;

    public:
        Blockchain(string name, int difficulty, int rewardForMining);
        void pushBlock(Block &block);
        void minePendingTransactions(string minerAddress);
        void createTransaction(Transaction transaction);
        double getBalanceofNode(string address);

        string toString();

};

#endif