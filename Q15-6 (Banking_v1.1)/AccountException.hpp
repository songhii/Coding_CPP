//
//  AccountException.hpp
//  Q15-6 (Banking_v1.1)
//
//  Created by songhee on 2020/12/26.
//

#ifndef AccountException_hpp
#define AccountException_hpp

#include "BankingCommonDecl.hpp"

class WithdrawException
{
private:
    int money;
    
public:
    WithdrawException(int m) : money(m)
    { }
    
    void ShowExceptionReason()
    {
        cout << "[예외 메시지: 잔액 보다 큰 " << money << " 원은 입력 불가]" << endl;
    }
};

class InputException
{
private:
    int money;
    
public:
    InputException(int m) : money(m)
    { }
    
    void ShowExceptionReason()
    {
        cout << "[예외 메시지: 0 보다 작은 " << money << " 원은 입력 불가]" << endl;
    }
};

#endif /* AccountException_hpp */
