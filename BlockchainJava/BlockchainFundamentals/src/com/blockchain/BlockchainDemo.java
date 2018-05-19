package com.blockchain;

/**
 * 
 * @author anubhp
 *
 */

public class BlockchainDemo {
	
	public static void main (String []args){
		Blockchain myBlockchain = new Blockchain("Ripple", 2, 75);
		myBlockchain.createTransaction(new Transaction("Rob", "Sam", 10));
		myBlockchain.createTransaction(new Transaction("Joseph", "Rob", 20));
		
		System.out.println("\nMy Blockchain: \n" + myBlockchain);
		
		myBlockchain.minePendingTransactions("Rob");
		
		System.out.println("\nMy Blockchain after mining the blocks: \n" + myBlockchain);
		
		myBlockchain.minePendingTransactions("Rob");
		
		System.out.println("\nMy Blockchain after mining the blocks second time: \n" + myBlockchain);
		
		System.out.println("\nBalance of Rob: " + myBlockchain.getBalanceofNode("Rob"));
		
	}

}
