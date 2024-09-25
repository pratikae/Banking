#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

class Account {
  // declaration of all public functions/variables for account class
  public:
    Account();
    Account(const Account&);
    Account& operator=(const Account&);
    void SetID(int);
    void SetName(string);
    void SetBalance(float);
    void SetAccountType(int);
    int GetID();
    string GetName();
    float GetBalance();
    int GetAccountType();
    virtual void Deposit(float);
    virtual void Withdraw(float);
    virtual Account& operator+=(Account&);
    ~Account();

  // declaration of all protected functions/variables for account class
  protected: 
    int* accountID;
    string customerName;
    float balance;
    int accountType;
};

#endif
