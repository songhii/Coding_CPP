//
//  Account.cpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#include "Account.hpp"
#include "BankingCommonDecl.hpp"

Account::Account(int ID, char *name, int balance)
{
    this->ID = ID;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
    this->balance = balance;
}

Account::Account(const Account& copy)
: ID(copy.ID), balance(copy.balance)
{
    name = new char[strlen(copy.name)+1];
    strcpy(name, copy.name);
}

Account& Account::operator=(const Account& ref)
{
    ID = ref.ID;
    balance = ref.balance;
    
    delete []name;
    name = new char[strlen(ref.name)+1];
    strcpy(name, ref.name);
    
    return *this;
}

void Account::Deposit(int money)
{
    this->balance += money;
}

void Account::Withdraw(int money)
{
    if(this->balance >= money)
    {
        this->balance -= money;
    }
    else
    {
        cout << "잔액이 부족합니다. (출금액: " << money << " > 잔액: " << this->balance << ")" << endl;
    }
}

void Account::ShowInfo() const
{
    cout << "계좌ID: " << this->ID << endl;
    cout << "이 름: " << this->name << endl;
    cout << "잔 액: " << this->balance << endl;
}

int Account::GetID() const
{
    return ID;
}

Account::~Account()
{
    delete []name;
}
