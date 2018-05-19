package com.blockchain;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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
public class Blockchain {
	private String name;
	private List<Block> chain;
	private int difficulty;
	private List<Transaction> pendingTransactions;
	private double rewardForMining;
	
	public Blockchain(String name, int difficulty, int rewardForMining) {
		this.name = name;
		this.chain = new ArrayList<Block>();
		Transaction []  dummyTransaction = {new Transaction("GenesisSender", "GenesisReceiver", 0)};
		this.chain.add(new Block(new ArrayList<Transaction>(Arrays.asList(dummyTransaction))));
		this.difficulty = difficulty;
		this.pendingTransactions = new ArrayList<Transaction>();
		this.rewardForMining = rewardForMining;
	}
	
	/**
	 * to add the block in the blockchain
	 * @param block: new block to be added
	 */
	public void pushBlock(Block block){
		block.setPrevHash(chain.get(chain.size()-1).getHash());
		block.mineBlock(difficulty);
		chain.add(block);
	}
	
	
	/**
	 * to mine the pending/unconfirmed transactions.
	 * @param minerAddress: address to which the reward will be transferred after mining and adding the block
	 */
	public void minePendingTransactions(String minerAddress){
		Block block = new Block(pendingTransactions);
		pushBlock(block);
		pendingTransactions.clear();
		pendingTransactions.add(new Transaction(name, minerAddress, rewardForMining));
	}
	
	
	/**
	 * to add a transaction into the list of pending transactions.
	 * @param transaction: new transaction made
	 */
	public void createTransaction(Transaction transaction){
		pendingTransactions.add(transaction);
	}
	
	
	/**
	 * 
	 * @param address
	 * @return the balance of the node given its address
	 */
	public double getBalanceofNode(String address) {
		double balance = 0;
		for (Block block : chain){
			for (Transaction transaction : block.getTransactions()) {
				if (transaction.getSender().equals(address)) {
					balance -= transaction.getAmount();
				}
				if (transaction.getReceiver().equals(address)) {
					balance += transaction.getAmount();
				}
			}
		}
		return balance;
	}

	@Override
	public String toString() {
		return "Blockchain: [\n\tname=" + name + ", \n\tchain=" + chain + ", \n\tdifficulty=" + difficulty + ", \n\tpendingTransactions="
				+ pendingTransactions + ", \n\trewardForMining=" + rewardForMining + "\n\t]";
	}
	
	
	
	

}
