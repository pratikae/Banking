#ifndef ACCOUNTCHECKINGH
#define ACCOUNTCHECKINGH

#include <iostream>
#include <cstdlib>
#include "Account.h"

class AccountChecking : public Account {
    private:
        float transactionFee;
    public:
        AccountChecking();
        AccountChecking(int, string, float, float);
        AccountChecking(const AccountChecking&);
        AccountChecking& operator=(const AccountChecking&);
        void SetTransactionFee(float);
        float GetTransactionFee();
        void Deposit(float) override;
        void Withdraw(float) override;
        ~AccountChecking();
};

#endif