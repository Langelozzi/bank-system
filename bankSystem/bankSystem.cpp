// bankSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Header files that have been imported
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>

//Customer class that contains a persons first and last name and can print out their full name properly
class Customer {
public:
    std::string fName;
    std::string lName;
    
    //Default constructor
    Customer() {};
    
    //Constructor
    Customer(std::string first, std::string last) {
        fName = first;
        lName = last;
    }

    void printName() {
        std::cout << fName << " " << lName << std::endl; 
    }
};

// Account class that has information about a customers account
class Account {
//this are only available within the class definition
private:
    std::string accountType;
    int balance;

//available outside the class definition
public:
    Customer owner;
    
    //constuctor method
    Account(Customer own, std::string accType, int bal)
        :owner(own), accountType(accType), balance(bal)
    {
        
    }
    
    // Shows balance in this account
    void viewBalance() {
        std::cout << std::endl << "Your current balance: $" << this->balance << std::endl << std::endl;
    }
    
    // Adds an amount to the persons account
    void deposit(int amount) {
        //bug: not actually updating when called
        this->balance += amount;
        std::cout << std::endl << "Your updated balance: $" << this->balance << std::endl << std::endl;
    }
    
    // Takes away an amount from the persons account
    void withdraw(int amount) {
        //bug: not actually updating when called
        this->balance -= amount;
        std::cout << std::endl << "Your updated balance: $" << this->balance << std::endl << std::endl;
    }

    // Shows the information about their account
    void printAccount() {
        std::cout << std::endl << "Owner: ";
        owner.printName();
        
        std::cout << "Account Type: ";
        std::cout << accountType << std::endl;
        
        std::cout << "Current Balance: $";
        std::cout << this->balance << std::endl << std::endl;

    }
};


// The bank class that represents all the accounts in a bank with a name
class Bank {
private:
    std::string name;

public:
    std::vector<Account> accounts;
    
    Bank(std::string nam) {
        name = nam;
    }

    //creates an account object and appends it to the vector of all the accounts
    Account createAccount(Customer own, std::string accType, int amount) {
        Account newAccount = Account(own, accType, amount);
        
        //append account to the end of the vector
        accounts.push_back(newAccount);

        //returns the new account that was just created
        return newAccount;
    }
};

//function that prompts for login credentials and returns the account of the person
Account login(Bank bank) {
    std::cout << "<--Login-->";

    std::string first;
    std::cout << std::endl << "First Name: ";
    std::cin >> first;

    std::string last;
    std::cout << "Last Name: ";
    std::cin >> last;

    //iterates through all of the accounts in the bank and if the name given matches the account name then it authenticates them
    for (int i = 0; i < bank.accounts.size(); i++) {
        Account current = bank.accounts[i];

        if (current.owner.fName == first && current.owner.lName == last) {
            return current;
        }
    }

    //if there is no match then notify them that their account credentials didnt match and exit the system
    std::cout << std::endl << "No accounts match the credentials provided" << std::endl;
    exit(0);
};

int main()
{   
    //setting a bank object and a starting user input value for the loop
    Bank bank("Default Bank");
    int userInput = 1;
    
    //will stop when the user types '5'
    while (userInput != 5) {
        
        //prints out the options for the user
        std::cout << "<---------What would you like to do today?--------->" << std::endl << std::endl;
        std::cout << "1: Create a new account" << std::endl;
        std::cout << "2: View my current balance" << std::endl;
        std::cout << "3: Withdraw from my account" << std::endl;
        std::cout << "4: Deposit to my account" << std::endl;
        std::cout << "5: Exit" << std::endl;

        //gets the user input and assigns it to the variable userInput
        std::cout << std::endl << "Enter your choice here: ";
        std::cin >> userInput;
        std::cout << std::endl;

        //what happens when they select create new account
        if (userInput == 1) {
            std::cout << "<--Please enter your information below-->" << std::endl;

            //getting information from the user
            std::string firstName;
            std::cout << "First name: ";
            std::cin >> firstName;

            std::string lastName;
            std::cout << "Last name: ";
            std::cin >> lastName;

            std::string accountType;
            std::cout << "Account Type (Savings or Checking): ";
            std::cin >> accountType;

            int startingBalance;
            std::cout << "Amount to start with: $";
            std::cin >> startingBalance;

            //creates a customer object and then uses it to create a new account in the bank
            Customer newCustomer = Customer(firstName, lastName);
            Account newAccount = bank.createAccount(newCustomer, accountType, startingBalance);

            //prints out the information for the user to see about their new account
            std::cout << std::endl << "<--Account created-->";
            newAccount.printAccount();
        }

        //if the user selects to view current balance then prompt for login and if login is successful then show them there current balance
        else if (userInput == 2) {
            Account user = login(bank);

            user.viewBalance();
        }

        //if the user selects to withdraw then prompt for login and if login is successful then ask how much they want and withdraw it from their account
        else if (userInput == 3) {
            Account user = login(bank);

            int withAmount;
            std::cout << std::endl << "How much would you like to withdraw today: $";
            std::cin >> withAmount;

            user.withdraw(withAmount);
        }
        
        //if the user selects to deposit then prompt for login and if login is successful then ask how much they want and deposit it from their account
        else if (userInput == 4) {
            Account user = login(bank);

            int depAmount;
            std::cout << std::endl << "How much would you like to deposit today: $";
            std::cin >> depAmount;

            user.deposit(depAmount);
        }
    }

    //once the user clicks 5 and exits the loop they are told to have a nice day
    std::cout << "Have a nice day!" << std::endl;
    exit(0);

    return 0;
}


