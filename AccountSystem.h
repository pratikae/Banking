#ifndef ACCOUNT_SYSTEM_H
#define ACCOUNT_SYSTEM_H

#include <iostream>
#include "Accounts.h" // includes accounts class functions and variables
using namespace std;

class AccountSystem {
  // delcaration of public variables/functions for accountSystems class
  public: 
    AccountSystem();
    void AddAccount();
    void Deposit();
    void Withdraw();
    void Transfer();
    void PrintAccounts();
    void LoadAccountSystem();
    void StoreAccountSystem();

  // delcaration of private variables/functions for accountSystems class
  private: 
    Accounts accounts;
};

#endif