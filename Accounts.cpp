#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include "Accounts.h"
using namespace std;

// default constructor
Accounts::Accounts() { size = 0; }

// adds account parameter to accounts array at index size
void Accounts::AddAccount(Account *acc) {
  accounts.push_back(acc);
  size++;
}

// parses through accounts array, returns index of id if found, returns -1 if not found
int Accounts::FindAccount(int id) {
  for (int i = 0; i < size; i++) {
    if (accounts[i]->GetID() == id) {
      return i;
    }
  }
  return -1;
}

// returns the account at index i of accounts array
Account &Accounts::at(const int i) { return *(accounts.at(i)); }

// gets size of accounts array
int Accounts::GetSize() { return size; }

void Accounts::LoadAccounts() {
  ifstream fin; // opens input stream
  fin.open("account.dat");
  
  if (fin.fail()) { // if file fails to open, inform user
    cout << "Note: accounts.dat file not found." << endl;
    cout << endl;
  }

  int numAccounts; 
  fin >> numAccounts; // take in numAccounts from file

  int id, type; // creates variables for id, type, balance, name
  float balance, fee;
  string name;

  for (int i = 0; i < numAccounts; i++) { // iterates through the file
    fin >> id >> type >> fee >> balance; // stores id and balance
    getline(fin, name); // stores name
    if (type == 1) {
      AccountChecking* acc = new AccountChecking(); // creates new Account object and sets all variables
      acc->SetID(id); 
      acc->SetAccountType(type);
      acc->SetBalance(balance);
      acc->SetName(name);
      acc->SetTransactionFee(fee);
      accounts.push_back(acc); // adds acc to the vector
      size++; // increases size variable
    } else if (type == 2) {
      AccountSaving* acc = new AccountSaving();
      acc->SetID(id); 
      acc->SetAccountType(type);
      acc->SetBalance(balance);
      acc->SetName(name);
      acc->SetMinimumBalance(fee);
      accounts.push_back(acc); // adds acc to the vector
      size++; // increases size variable
    } else {
      cout << "Error: invalid account type.";
    }
    
  }
  fin.close(); // closes input stream
}

void Accounts::StoreAccounts() {
  ofstream fout; // opens output stream
  fout.open("account.dat");
  
  if (fout.fail()) { // if file doesn't open or something, informs user
    cout << "Note: accounts.dat file not found." << endl;
    cout << endl;
  }

  fout << size << endl; // outputs size variable

  //use dynamic cast to change account[i], which is an pointer to an account object to a pointer to an AccountChecking object
  //then use the pointer to an AccountChecking object and call GetTransactionFee
  for (int i = 0; i < size; i++) { // iterates through the vector
    if (accounts[i]->GetAccountType() == 1) {
      fout << accounts[i]->GetID() << " " << " " << accounts[i]->GetTransactionFee() << " " << accounts[i]->GetBalance() << " "
         << accounts[i]->GetName() << endl; // outputs object at vector index i's variables
    }
  }

  fout.close(); // closes output stream
}

Accounts::~Accounts() { accounts.clear(); }