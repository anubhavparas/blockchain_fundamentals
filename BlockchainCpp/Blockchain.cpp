#include "Blockchain.h"
#include "utils.h"


using namespace std;
using namespace utils;

Blockchain::Blockchain(string name, int difficulty, int rewardForMining) {
    this->name = name;
    //this->chain = new ArrayList<Block>();
    vector<Transaction> dummyTransaction {Transaction("GenesisSender", "GenesisReceiver", 0)};
    this->chain.push_back(Block(dummyTransaction));
    this->difficulty = difficulty;
    //this->pendingTransactions = new ArrayList<Transaction>();
    this->rewardForMining = rewardForMining;
}


/**
 * to add the block in the blockchain
 * @param block: new block to be added
 */
void Blockchain::pushBlock(Block &block){
    block.setPrevHash(this->chain.back().getHash());
    block.mineBlock(this->difficulty);
    this->chain.push_back(block);
}


/**
 * to mine the pending/unconfirmed transactions.
 * @param minerAddress: address to which the reward will be transferred after mining and adding the block
 */
void Blockchain::minePendingTransactions(string minerAddress){
    Block block = Block(this->pendingTransactions);
    pushBlock(block);
    this->pendingTransactions.clear();
    this->pendingTransactions.push_back(Transaction(name, minerAddress, rewardForMining));
}


/**
 * to add a transaction into the list of pending transactions.
 * @param transaction: new transaction made
 */
void Blockchain::createTransaction(Transaction transaction){
    pendingTransactions.push_back(transaction);
}

/**
 * @param address
 * @return the balance of the node given its address
 */
double Blockchain::getBalanceofNode(string address) {
    double balance = 0;
    for (Block block : chain){
        for (Transaction transaction : block.getTransactions()) {
            if (transaction.getSender().compare(address) == 0) {
                balance -= transaction.getAmount();
            }
            if (transaction.getReceiver().compare(address) == 0) {
                balance += transaction.getAmount();
            }
        }
    }
    return balance;
}


string Blockchain::toString() {
    return "Blockchain: [\n\tname=" + name + ", \n\tchain=" + vectorToString(chain) + ", \n\tdifficulty=" + to_String(difficulty) + ", \n\tpendingTransactions="
            + vectorToString(pendingTransactions) + ", \n\trewardForMining=" + to_String(rewardForMining) + "\n\t]";
}
	


	
