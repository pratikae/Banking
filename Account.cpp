#include <iostream>
using namespace std;

#include "Account.h"

// default constructor
Account::Account() {  
  accountID = new int(0);
  customerName = "none";
  balance = 0.0;
}

// copy constructor
Account::Account(const Account &acc) { 
  accountID = new int;
  *accountID = *(acc.accountID);
  balance = acc.balance;
  customerName = acc.customerName;
}

//copy assignment
Account& Account::operator=(const Account &acc) { 
  if (this != &acc) {
    accountID = acc.accountID;
    customerName = acc.customerName;
    balance = acc.balance;
  }
  return *this;
}

// += operation overload
Account& Account::operator+=(Account &acc) {
  if (this != &acc) {
    balance += acc.balance;
  }
  return *this;
}

// sets id to is parameter
void Account::SetID(int id) { 
  *accountID = id; 
}

// sets name to name parameter
void Account::SetName(string name) { customerName = name; } 

// sets balance to balance parameter
void Account::SetBalance(float b) { balance = b; } 

// sets accountType to t
void Account::SetAccountType(int t) { accountType = t; }

// returns id
int Account::GetID() { 
  return *accountID; 
}

// returns name
string Account::GetName() { return customerName; }

// returns balance
float Account::GetBalance() { return balance; }

// returns accountType
int Account::GetAccountType() { return accountType; }

// deposits d into balance
void Account::Deposit(float d) { balance += d; }

// withdraws w into balance
void Account::Withdraw(float w) { balance -= w; }

// account destructor 
Account::~Account() {
  delete accountID;
  balance = 0;
  customerName = "none";
}