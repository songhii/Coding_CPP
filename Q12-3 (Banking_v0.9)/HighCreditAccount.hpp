//
//  HighCreditAccount.hpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#ifndef HighCreditAccount_hpp
#define HighCreditAccount_hpp

#include "NormalAccount.hpp"

class HighCreditAccount : public NormalAccount
{
private:
    int rank;
    
public:
    HighCreditAccount(int ID, String name, int balance, int rate, int rank);
    virtual void Deposit(int money);
};

HighCreditAccount::HighCreditAccount(int ID, String name, int balance, int rate, int rank)
: NormalAccount(ID, name, balance, rate), rank(rank)
{ }

void HighCreditAccount::Deposit(int money)
{
    double interest = money * rank * 0.01;
    NormalAccount::Deposit(money);
    Account::Deposit(interest);
}

#endif /* HighCreditAccount_hpp */
