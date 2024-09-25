#ifndef ACCOUNTSAVINGH
#define ACCOUNTSAVINGH

#include "Account.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class AccountSaving : public Account {

    private:
        float minimumBalance;
    public:
        AccountSaving();
        AccountSaving(int, string, float, float);
        AccountSaving(const AccountSaving&);
        AccountSaving& operator=(const AccountSaving&);
        Account& operator+=(Account&) override;
        void Withdraw(float) override;
        void SetMinimumBalance(float);
        float GetMinimumBalance();
        ~AccountSaving();

};

#endif