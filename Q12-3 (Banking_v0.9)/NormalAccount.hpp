//
//  NormalAccount.hpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#ifndef NormalAccount_hpp
#define NormalAccount_hpp

#include "Account.hpp"

class NormalAccount : public Account
{
private:
    int rate;
    
public:
    NormalAccount(int ID, char* name, int balance, int rate);
    virtual void Deposit(int money);
};

NormalAccount::NormalAccount(int ID, char* name, int balance, int rate)
: Account(ID, name, balance), rate(rate)
{ }

void NormalAccount::Deposit(int money)
{
    double interest = money * rate * 0.01;
    money += interest;
    Account::Deposit(money);
}

#endif /* NormalAccount_hpp */
