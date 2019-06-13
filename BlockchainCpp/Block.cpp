#include "Block.h"
#include "sha256.h"
#include "utils.h"


using namespace std;
using namespace utils; 

Block::Block(vector<Transaction> transactions) {
    this->prevHash = string();
    this->timeStamp = time(0);
    this->transactions = transactions;
    this->nonce = 0;
    this->hash = this->calculateHash();
}

string Block::getPrevHash() {
	return prevHash;
}
void Block::setPrevHash(string prevHash) {
    this->prevHash = prevHash;
}
time_t Block::getTimeStamp() {
    return timeStamp;
}
void Block::setTimeStamp(time_t timeStamp) {
    this->timeStamp = timeStamp;
}
vector<Transaction> Block::getTransactions() {
    return transactions;
}
void Block::setTransactions(vector<Transaction> transactions) {
    this->transactions = transactions;
}
string Block::getHash() {
    return hash;
}
void Block::setHash(string hash) {
    this->hash = hash;
}
long Block::getNonce() {
    return nonce;
}
void Block::setNonce(long nonce) {
    this->nonce = nonce;
}

string Block::timeToString(time_t timeStamp){
    tm *ltm = localtime(&timeStamp);
    return to_String(1+ltm->tm_hour) + ":" + to_String(1+ltm->tm_min) + ":" + to_String(1+ltm->tm_sec) + "." +
        to_String(ltm->tm_mday) + "-" + to_String(1+ltm->tm_mon) + "-" + to_String(1900+ltm->tm_year);
}

string Block::toString() {
    return "\n\t\tBlock: [\n\t\t\ttimeStamp=" + this->timeToString(this->timeStamp) + ", \n\t\t\ttransactions=" + vectorToString(this->transactions) + "\n\t\t\tprevHash=" + this->prevHash + ", \n\t\t\thash="
				+ this->hash + ", \n\t\t\tnonce=" + to_String(this->nonce) + "\n\t\t]";
}

string Block::calculateHash() {
    return sha256(this->toString());
}

void Block::mineBlock(int difficulty) {
    string difficultyZeroString = "";
		for (int i = 1; i <= difficulty; i++){
			difficultyZeroString += "0";
		}
		this->nonce = 0;
		while (this->hash.substr(0, difficulty).compare(difficultyZeroString) != 0) {
			this->nonce += 1;
			this->hash = calculateHash();
		}

}



