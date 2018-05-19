package com.blockchain;


/**
 * 
 * @author anubhp
 * 
 * sender: address of the sender.
 * receiver: address of the receiver.
 * amount: amount/number of money/coins transferred.
 *
 */
public class Transaction {
	private String sender;
	private String receiver;
	private double amount;
	public Transaction(String sender, String receiver, double amount) {
		super();
		this.sender = sender;
		this.receiver = receiver;
		this.amount = amount;
	}
	public String getSender() {
		return sender;
	}
	public void setSender(String sender) {
		this.sender = sender;
	}
	public String getReceiver() {
		return receiver;
	}
	public void setReceiver(String receiver) {
		this.receiver = receiver;
	}
	public double getAmount() {
		return amount;
	}
	public void setAmount(double amount) {
		this.amount = amount;
	}
	@Override
	public String toString() {
		return "Transaction [sender=" + sender + ", receiver=" + receiver + ", amount=" + amount + "]";
	}
	
}
