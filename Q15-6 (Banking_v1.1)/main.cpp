//
//  main.cpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#include "BankingCommonDecl.hpp"
#include "AccountHandler.hpp"

int main(int argc, const char * argv[])
{
    AccountHandler handler;
    
    int opt;
    
    while(1) {
        handler.ShowMenu();
        cout << "선택: ";
        cin >> opt;
        cout << endl;
        
        switch(opt)
        {
            case 1:
                handler.MakeAccount();
                break;
            case 2:
                handler.DepositMoney();
                break;
            case 3:
                handler.WithdrawMoney();
                break;
            case 4:
                handler.ShowAllInfo();
                break;
            case 5:
                return 0;
        }
        
    }
    return 0;
}
