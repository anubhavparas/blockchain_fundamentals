
# ## This is a sample code to create a dummy blockchain in python.
# ### This consists of:
# - Making transactions
# - Mining pending transactions
# - Proof-of-work algorithm to mine the blocks and adding them in the blockchain.


import hashlib as hasher
import datetime as date
import numpy as np


## Transaction object
# It has:
#    senderAddress: address of the sender.
#    receiverAddress: address of the receiver.
#    amount: amount/number of money/coins transferred.
##########################################################################

class Transaction:
    def __init__(self, senderAddress, receiverAddress, amount):
        self.senderAddress = senderAddress
        self.receiverAddress = receiverAddress
        self.amount = amount

    def __repr__(self):
        return "Transaction [sender = {}, receiver = {}, amount = {}]".format(
            self.senderAddress, self.receiverAddress, self.amount
        )

##########################################################################


## Block object
# It has: 
#    timestamp: when was the block the created.
#    transactions: transations corresponding to that block.
#    nonce: random number to be calculated so that the hash of the the block has some features(here, hash will start from some number of zeros)
#    prev_hash: contains the hash of the previous block in the blockchain.
#    hash: contains the hash of the block.
#    calculate_hash(): to calculate the hash of the block.
#    mine_block(): mine the block with the difficulty number.
##########################################################################

class Block:
    def __init__(self, transactions):
        self.timestamp = date.datetime.now()
        self.transactions = transactions
        self.nonce = 0
        self.prev_hash = ""
        self.hash = self.calculate_hash()

    def calculate_hash(self):
        sha = hasher.sha256()
        sha.update(
            str(self.timestamp).encode("utf-8") + 
            str(self.prev_hash).encode("utf-8") + 
            str(self.transactions).encode("utf-8") + 
            str(self.nonce).encode("utf-8")
        )
        return sha.hexdigest()

    def mine_block(self, difficulty):
        difficulty_string = ""
        difficulty_string = difficulty_string.join(["0"] * difficulty) #  can be done this way too -> difficulty_string.join(str (zero) for zero in np.zeros(difficulty, dtype = int).tolist())
        self.nonce = 0
        while(self.hash[:difficulty] != difficulty_string):
            self.nonce += 1
            self.hash = self.calculate_hash()

    
    def __repr__(self):
        return "\n\t\tBlock: [\n\t\t\ttimeStamp = {}, \n\t\t\ttransactions = {}, \n\t\t\tprevHash = {}, \n\t\t\thash = {}, \n\t\t\tnonce = {} \n\t\t]".format(
            self.timestamp, self.transactions, self.prev_hash, self.hash, self.nonce
        )

##########################################################################


## Blockchain object
# It has:
#    name: name of the blockchain.
#    chain: array of blocks.
#    difficulty: difficulty of the blockchain to validate the block (here, number of zeros at the start of the hash of every block for the hash to be a valid hash).
#    pending_transactions: list of pending/unconfirmed transactions
#    reward_for_mining: reward/token amount/coins given to the miners for mining the block and adding a valid block in the blockchain.
#    push_block(): to add the block in the blockchain,
#    mine_pending_transactions(): mine the pending/unconfirmed transactions.
#    create_transaction(): add a transaction into the list of pending transactions.
#    get_balance_of_node(): to fetch the balance of a node given its address.
##########################################################################

class Blockchain:
    def __init__(self, name = 'MSCoin', difficulty = 3, reward_for_mining = 75):
        self.name = name
        self.chain = [Block([Transaction("GenesisSender", "GenesisReceiver", 0)])]
        self.difficulty = difficulty
        self.pending_transactions = []
        self.reward_for_mining = reward_for_mining

    def push_block(self, block):
        block.prev_hash = self.chain[len(self.chain) - 1].hash
        block.mine_block(self.difficulty)
        self.chain.append(block)

    def mine_pending_transactions(self, miner_address):
        block = Block(self.pending_transactions)
        self.push_block(block)
        self.pending_transactions = []
        self.pending_transactions.append(Transaction(self.name, miner_address, self.reward_for_mining))
   
    def create_transaction(self, transaction):
        self.pending_transactions.append(transaction)

    def get_balance_of_node(self, address):
        balance = 0
        for block in self.chain:
            for transaction in block.transactions:
                if (transaction.senderAddress == address):
                    balance -= transaction.amount
                if (transaction.receiverAddress == address):
                    balance += transaction.amount
        return balance

    def __repr__(self):
        return "Blockchain: [\n\tname = {}, \n\tchain = {}, \n\tdifficulty = {}, \n\tpendingTransactions = {}, \n\trewardForMining = {} \n\t\t]".format(
            self.name, self.chain, self.difficulty, self.pending_transactions, self.reward_for_mining
        )

##########################################################################


# Demo

if __name__ == '__main__':
    my_block_chain = Blockchain("MSCoin", 3, 75)
    my_block_chain.create_transaction(Transaction("Rob", "Sam", 10))
    my_block_chain.create_transaction(Transaction("Sam", "David", 40))

    print("Blockchain after creating transactions. \n" + str(my_block_chain))

    my_block_chain.mine_pending_transactions("Rob")
    print("\n\nBlockchain after mining. \n" + str(my_block_chain))

    my_block_chain.mine_pending_transactions("Sam")
    print("\n\nBlockchain after mining second time. \n" + str(my_block_chain))

    print("\n\nBalance of Rob\n" + str(my_block_chain.get_balance_of_node("Rob")))

