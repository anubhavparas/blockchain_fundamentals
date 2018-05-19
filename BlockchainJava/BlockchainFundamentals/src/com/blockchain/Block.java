package com.blockchain;

import java.util.Date;
import java.util.List;

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
public class Block {
	 private String prevHash;
	 private Date timeStamp;
	 private List<Transaction> transactions;
	 private String hash;
	 private long nonce;
	 
	 public Block(List<Transaction> transactions) {
			this.prevHash = null;
			this.timeStamp = new Date();
			this.transactions = transactions;
			this.nonce = 0;
			this.hash = calculateHash();
		}

	
	 /**
	 * to calculate the hash of the block.
	 * @return hash of the block
	 */
	 public String calculateHash() {
		return CryptoSHA256.getSha256(this.toString());
	}
	
	
	 /**
	  * to mine the block with the given difficulty number.
	  * @param difficulty: here, number of zeros at the start of the hash of every block for the hash to be a valid hash.
	  */
	 public void mineBlock(int difficulty) {
		String difficultyZeroString = "";
		for (int i = 1; i <= difficulty; i++){
			difficultyZeroString += "0";
		}
		this.nonce = 0;
		while (!this.hash.substring(0, difficulty).equals(difficultyZeroString)) {
			this.nonce += 1;
			this.hash = calculateHash();
		}
	}
	
	public String getPrevHash() {
		return prevHash;
	}
	public void setPrevHash(String prevHash) {
		this.prevHash = prevHash;
	}
	public Date getTimeStamp() {
		return timeStamp;
	}
	public void setTimeStamp(Date timeStamp) {
		this.timeStamp = timeStamp;
	}
	public List<Transaction> getTransactions() {
		return transactions;
	}
	public void setTransactions(List<Transaction> transactions) {
		this.transactions = transactions;
	}
	public String getHash() {
		return hash;
	}
	public void setHash(String hash) {
		this.hash = hash;
	}
	public long getNonce() {
		return nonce;
	}
	public void setNonce(long nonce) {
		this.nonce = nonce;
	}
	


	@Override
	public String toString() {
		return "\n\t\tBlock: [\n\t\t\ttimeStamp=" + timeStamp + ", \n\t\t\ttransactions=" + transactions + "\n\t\t\tprevHash=" + prevHash + ", \n\t\t\thash="
				+ hash + ", \n\t\t\tnonce=" + nonce + "\n\t\t]";
	}
	
	
	

}
