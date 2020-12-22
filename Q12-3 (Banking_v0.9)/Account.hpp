//
//  Account.hpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#ifndef Account_hpp
#define Account_hpp

#include "String.hpp"

class Account
{
private:
    int ID;
    String cusName;
//    char *name;
    int balance;
    
public:
    Account(int ID, String name, int balance);
//    Account(const Account& copy);
//    Account& operator=(const Account& ref);
    
    int GetID() const;
    virtual void Deposit(int money);
    void Withdraw(int money);
    void ShowInfo() const;
//    ~Account();
};

#endif /* Account_hpp */
