#include "BankAccount.h"

BankAccount::BankAccount()
{
	balance = 0;
}

BankAccount::BankAccount(double bal)
{
	balance = bal;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

void BankAccount::withdraw(double amount)
{
	balance -= amount;
}

double BankAccount::checkBalance()
{
	return balance;
}

BankAccount::~BankAccount()
{
}
