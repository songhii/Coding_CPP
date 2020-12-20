//
//  AccountHandler.hpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#ifndef AccountHandler_hpp
#define AccountHandler_hpp

#include "Account.hpp"
#include "AccountArray.hpp"

class AccountHandler
{
private:
    int arrIdx;
    BoundCheckAccountPtrArray aptr;
    
public:
    AccountHandler();
    void ShowMenu() const;
    void MakeAccount();
    void MakeNormal();
    void MakeHighCredit();
    void DepositMoney();
    void WithdrawMoney();
    void ShowAllInfo();
    ~AccountHandler();
};

#endif /* AccountHandler_hpp */
