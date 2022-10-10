#include "BankAccount.h"

using namespace std;

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

bool BankAccount::withdraw(double amount)
{
	if (balance - amount < 0) {
		return false;
	}
	else {
		balance -= amount;
		return true;
	}
}

double BankAccount::checkBalance()
{
	return balance;
}

BankAccount::~BankAccount()
{
}
