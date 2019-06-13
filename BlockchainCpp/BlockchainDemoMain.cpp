#include <iostream> 
#include "Blockchain.h"
#include "utils.h"

using namespace utils;

using namespace std;

int main() {
    Blockchain myBlockchain = Blockchain("Ripple", 2, 75);
    myBlockchain.createTransaction(Transaction("Jeff", "Salil", 10));
    myBlockchain.createTransaction(Transaction("Alisha", "Raj", 20));
    
    cout << "\nMy Blockchain: \n" << myBlockchain.toString() << endl;
    
    myBlockchain.minePendingTransactions("Salil");
    
    cout << "\nMy Blockchain after mining the blocks: \n" << myBlockchain.toString() << endl;
    
    myBlockchain.minePendingTransactions("Salil");
    
    cout << "\nMy Blockchain after mining the blocks second time: \n" << myBlockchain.toString() << endl;
    
    cout << "\nBalance of Salil: " + to_String(myBlockchain.getBalanceofNode("Salil")) << endl;
}