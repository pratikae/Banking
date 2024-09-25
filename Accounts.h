#include "Account.h" // includes account class variables and functions
#include "AccountChecking.h"
#include "AccountSaving.h"

class Accounts {
  // declaration of public variables/functions for accounts class 
  public:
    Accounts();
    void AddAccount(Account*);
    int FindAccount(int);
    Account& at(const int i);
    int GetSize();
    void LoadAccounts();
    void StoreAccounts();
    ~Accounts();

  // declaration of private variables/functions for accounts class 
  private:
    vector<Account*> accounts;
    int size;

};
