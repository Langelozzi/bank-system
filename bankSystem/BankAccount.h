#pragma once
class BankAccount {
private:
	double balance;
public:
	BankAccount();
	
	BankAccount(double bal);
	
	void deposit(double amount);
	
	bool withdraw(double amount);
	
	double checkBalance();
	
	// destructor. It destroys the object instance and deallocates it from memory.
	~BankAccount();
};