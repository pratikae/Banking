#include "AccountSaving.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// default constructor
AccountSaving::AccountSaving() : Account() {
    minimumBalance = 0.0;
}

// constructor with parameters
AccountSaving::AccountSaving(int id, string name, float b, float m) {
    *accountID = id;
    customerName = name;
    balance = b;
    minimumBalance = m;
}

// copy constructors
AccountSaving::AccountSaving(const AccountSaving& acc) {
    accountID = new int;
    *accountID = *(acc.accountID);
    balance = acc.balance;
    customerName = acc.customerName;
    minimumBalance = acc.minimumBalance;
}

// copy assignment
AccountSaving& AccountSaving::operator=(const AccountSaving& acc) {
    if (this != &acc) {
    accountID = acc.accountID;
    customerName = acc.customerName;
    balance = acc.balance;
    minimumBalance = acc.minimumBalance;
    }
    return *this;
}

// += operator overload
Account& AccountSaving::operator+=(Account &acc) {
  Account::operator+=(acc);
  return *this;
}

// withdraw
void AccountSaving::Withdraw(float amount) {
    if (!((balance -= amount) < minimumBalance)) {
        Account::Withdraw(amount);
    }
}

// mutator
void AccountSaving::SetMinimumBalance(float b) {
    minimumBalance = b;
}

// accessor
float AccountSaving::GetMinimumBalance() {
    return minimumBalance;
}

// destructor
AccountSaving::~AccountSaving() {
    delete accountID;
    balance = 0;
    customerName = "none";
    minimumBalance = 0;
}