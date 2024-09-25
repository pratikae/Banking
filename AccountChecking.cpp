#include "AccountChecking.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// default constructor
AccountChecking::AccountChecking() : Account() {
    transactionFee = 0.0;
}

// constructor with parameters
AccountChecking::AccountChecking(int id, string name, float b, float t) {
    *accountID = id;
    customerName = name;
    balance = b;
    transactionFee = t;
}

// copy constructor
AccountChecking::AccountChecking(const AccountChecking& acc) {
    Account::operator=(acc);
    transactionFee = acc.transactionFee;
}

// copy assignment 
AccountChecking& AccountChecking::operator=(const AccountChecking& acc) {
    Account::operator=(acc);
    transactionFee = acc.transactionFee;
    return *this;
}

// mutator method
void AccountChecking::SetTransactionFee(float t) {
    transactionFee = t;
}

// accessor method
float AccountChecking::GetTransactionFee() {
    return transactionFee;
}

// deposit
void AccountChecking::Deposit(float amount) {
    Account::Deposit(amount);
    balance -= transactionFee;
}

// withdraw
void AccountChecking::Withdraw(float amount) {
    Account::Withdraw(amount);
    balance -= transactionFee;
}

// destructor
AccountChecking::~AccountChecking() {
    delete accountID;
    balance = 0;
    customerName = "none";
    transactionFee = 0;
}