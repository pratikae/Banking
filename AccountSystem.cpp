#include <iostream>
#include <string>
#include <iomanip>

#include "AccountSystem.h"
using namespace std;

void AccountSystem::AddAccount() {
  int id;
  string name;
  float amount;
  
  cout << "Enter account id: "; // prompts user for account object's values
  cin >> id;
  cout << "Enter customer account name: ";
  getline(cin, name);
  getline(cin, name);
  cout << "Enter initial deposit amount: $ ";
  cin >> amount;
  
  if (accounts.FindAccount(id) != -1) { // checks if account exists already
    cout << "Account already exists. Please try again." << endl;
  } else {
    Account a; // creates new account object
    a.SetID(id); // sets each value to user given value
    a.SetName(name);
    a.SetBalance(amount);

    accounts.AddAccount(a); // adds account to accounts array

    cout << "Added new account id " << id << " with initial balance $"
         << amount << endl;
  }
}

void AccountSystem::Deposit() {
  if (accounts.GetSize() == 0) { // tells user if array is empty
    cout << "Empty account list." << endl;
    return;
  }

  int id;
  float amount;
  cout << "Enter account id: "; // asks user for id number
  cin >> id;
  
  int accountIndex = accounts.FindAccount(id);
  if (accountIndex == -1) { // if id doesnt exist, exits function
    cout << "Error: account with id " << id << " not found." << endl;
  } else { // asks for amount and deposits
    cout << "Enter the deposit amount: $ ";
    cin >> amount;
    accounts.at(accountIndex).Deposit(amount); // calls at function and deposit function
    cout << "Deposited $" << amount << " into account id " << id << endl;
  }
}

void AccountSystem::Withdraw() {
  if (accounts.GetSize() == 0) { // tells user if array is empty
    cout << "Empty account list." << endl;
    return;
  }

  int id;
  float amount;
  cout << "Enter account id: "; // asks user for account id
  cin >> id;
  

  int accountIndex = accounts.FindAccount(id);
  if (accountIndex == -1) { // if id doesnt exists, tells user
    cout << "Error: account with id " << id << " not found." << endl;
    return;
  } 
  
  cout << "Enter the withdraw amount: $ "; // asks for withdraw amount
  cin >> amount;
  if (accounts.at(accountIndex).GetBalance() < amount) { // if balance of account is too low, error
    cout << "Error: failed to withdraw $" << amount << " from account id " << id
         << endl;
  } else {
    accounts.at(accountIndex).Withdraw(amount); // calls at and withdraw functions
    cout << "Withdrawn $" << amount << " into account id " << id << endl;
  }
}

void AccountSystem::Transfer() {
  if (accounts.GetSize() == 0) { // tells user if array is empty
    cout << "Empty account list." << endl;
    return;
  }

  int source, dest;
  float amount;
  cout << "Enter source account id: "; // prompts user for source and dest account ids
  cin >> source;
  cout << "Enter destination account id: ";
  cin >> dest;
  cout << "Enter the tranfer amount: $ ";
  cin >> amount;

  int accountIndexSource = accounts.FindAccount(source); // calls at to store index of source and dest
  int accountIndexDest = accounts.FindAccount(dest);
  if (accountIndexSource == -1 || accountIndexDest == -1) { // if one account doesnt exist, error
    cout << "Error: Source or destination account number not found. Operation "
            "failed."
         << endl;
  } else if (accounts.at(accountIndexSource).GetBalance() < amount) { // if source doesn't have enough moeny to transfer, error
    cout << "Error: Insufficient balance. Source account has only "
         << accounts.at(accountIndexSource).GetBalance() << " in the balance.";
  } else {
    accounts.at(accountIndexDest).Deposit(amount); // deposits amount into dest
    accounts.at(accountIndexSource).Withdraw(amount); // withdraws amount out of source
    cout << "Successfully transferred amount $" << amount
         << " from source account id " << source
         << " to destination account id " << dest << endl;
  }
}

void AccountSystem::PrintAccounts() { 
  if (accounts.GetSize() == 0) { // tells user if array is empty
    cout << "Empty account list." << endl;
    return;
  }

  // sets spacing and prints every account in the accounts array
  cout << "+--------------------------------------------------------+" << endl;
  cout << "| Acct | Customer Account Name         | Balance         |" << endl;
  for (int i = 0; i < accounts.GetSize(); i++) {
    cout << "+--------------------------------------------------------+"
         << endl;
    cout << "| " << left << setw(4) << accounts.at(i).GetID() << " | " << setw(29) << accounts.at(i).GetName()
         << " | $" << right << setw(14) << accounts.at(i).GetBalance() << " |" << endl;
  }
  cout << "+--------------------------------------------------------+" << endl;
}

void AccountSystem::LoadAccountSystem() {
  accounts.LoadAccounts();
}

void AccountSystem::StoreAccountSystem() {
  accounts.StoreAccounts();
}