//
//  Account.cpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#include "Account.hpp"
#include "BankingCommonDecl.hpp"

Account::Account(int ID, String name, int balance)
: ID(ID), balance(balance)
{
    cusName = name;
}

void Account::Deposit(int money)
{
    if(money < 0)
    {
        InputException expn(money);
        throw expn;
    }
    this->balance += money;
}

void Account::Withdraw(int money)
{
    if(money < 0)
    {
        InputException expn(money);
        throw expn;
    }
    if(this->balance < money)
    {
        WithdrawException expn(money);
        throw expn;
    }
    this->balance -= money;
}

void Account::ShowInfo() const
{
    cout << "계좌ID: " << this->ID << endl;
    cout << "이 름: " << cusName << endl;
    cout << "잔 액: " << this->balance << endl;
}

int Account::GetID() const
{
    return ID;
}
