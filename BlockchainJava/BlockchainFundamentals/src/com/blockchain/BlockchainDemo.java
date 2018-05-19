package com.blockchain;

/**
 * 
 * @author anubhp
 *
 */

public class BlockchainDemo {
	
	public static void main (String []args){
		Blockchain myBlockchain = new Blockchain("Ripple", 2, 75);
		myBlockchain.createTransaction(new Transaction("Jeff", "Salil", 10));
		myBlockchain.createTransaction(new Transaction("Alisha", "Raj", 20));
		
		System.out.println("\nMy Blockchain: \n" + myBlockchain);
		
		myBlockchain.minePendingTransactions("Salil");
		
		System.out.println("\nMy Blockchain after mining the blocks: \n" + myBlockchain);
		
		myBlockchain.minePendingTransactions("Salil");
		
		System.out.println("\nMy Blockchain after mining the blocks second time: \n" + myBlockchain);
		
		System.out.println("\nBalance of Salil: " + myBlockchain.getBalanceofNode("Salil"));
		
	}

}
