//
//  Account.hpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#ifndef Account_hpp
#define Account_hpp

#include "String.hpp"
#include "AccountException.hpp"

class Account
{
private:
    int ID;
    String cusName;
    int balance;
    
public:
    Account(int ID, String name, int balance);
    
    int GetID() const;
    virtual void Deposit(int money);
    void Withdraw(int money);
    void ShowInfo() const;
};

#endif /* Account_hpp */
