#include <iostream>

#include "BankAccount.h"

using namespace std;

int main() {
	BankAccount account = BankAccount(1000);
	
	int decision = 0;

	cout << "Welcome to the Bank!" << endl;

	while (decision != 4) {
		cout << endl << "1 - View Balance" << endl;
		cout << "2 - Deposit" << endl;
		cout << "3 - Withdraw" << endl;
		cout << "4 - Exit" << endl;

		cout << "Please choose an option to continue: ";
		cin >> decision;

		if (decision == 1) {
			cout << "Current balance: " << account.checkBalance() << endl;
		} else if(decision == 2) {
			double amount;
		
			cout << "How much would you like to deposit: ";
			cin >> amount;

			cout << "Old balance: " << account.checkBalance() << endl;

			account.deposit(amount);

			cout << "New balance: " << account.checkBalance() << endl;
		}
		else if (decision == 3) {
			double amount;

			cout << "How much would you like to withdraw: ";
			cin >> amount;

			double oldBalance = account.checkBalance();

			bool success = account.withdraw(amount);

			if (success) {
				cout << "Old balance: " << oldBalance << endl;
				cout << "New balance: " << account.checkBalance() << endl;
			}
			else {
				cout << "You can not withdraw more money than you have!" << endl;
			}
		}
	}

	cout << endl << "Thank you for using the Bank ATM. Have a good day!" << endl;
	
	return 0;
}