//
//  AccountHandler.cpp
//  Q09-3 (Banking_v0.7)
//
//  Created by songhee on 2020/12/11.
//

#include "AccountHandler.hpp"
#include "BankingCommonDecl.hpp"
#include "Account.hpp"
#include "NormalAccount.hpp"
#include "HighCreditAccount.hpp"

AccountHandler::AccountHandler()
: arrIdx(0)
{ }

void AccountHandler::ShowMenu() const
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount()
{
    int opt;
    
    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << "\n" << "선택: ";
    cin >> opt;
    
    switch(opt)
    {
        case 1:
            MakeNormal();
            break;
        case 2:
            MakeHighCredit();
            break;
        default:
            cout << "유효하지 않은 번호입니다. 다시 입력해주세요." << endl;
            cout << endl;
    }
}

void AccountHandler::MakeNormal()
{
    int id;
//    char name[NAME_LEN];
    String name;
    int bal;
    int rate;
    
    cout << "[보통예금계좌 개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
//    cout << "### name 객체: " << name << endl;
    cout << "입금액: ";
    cin >> bal;
    cout << "이자율: ";
    cin >> rate;
    cout << endl;
    
    aptr[arrIdx++] = new NormalAccount(id, name, bal, rate);
}

void AccountHandler::MakeHighCredit()
{
    int id;
//    char name[NAME_LEN];
    String name;
    int bal;
    int rate;
    int rank;
    
    cout << "[신용신뢰계좌 개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> bal;
    cout << "이자율: ";
    cin >> rate;
    cout << "신용등급(1toA, 2toB, 3toC): ";
    cin >> rank;
    switch(rank)
    {
        case 1:
            rank = LEVEL_A;
            break;
        case 2:
            rank = LEVEL_B;
            break;
        case 3:
            rank = LEVEL_C;
            break;
    }
    cout << endl;
    
    aptr[arrIdx++] = new HighCreditAccount(id, name, bal, rate, rank);
}

void AccountHandler::DepositMoney()
{
    int id, money;
    cout << "[입  금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> money;
    
    int i;
    bool check = false;
    for(i = 0; i < arrIdx; i++)
    {
        if(aptr[i]->GetID() == id)
        {
            check = true;
            break;
        }
    }
    if(check)
    {
        aptr[i]->Deposit(money);
        cout << "입금완료" << endl;
    }
    else
        cout << "입력한 계좌ID와 일치하는 계좌가 없습니다." << endl;
    cout << endl;
}

void AccountHandler::WithdrawMoney()
{
    int id, money;
    cout << "[출  금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> money;
    
    int i;
    bool check = false;
    for(i = 0; i < arrIdx; i++)
    {
        if(aptr[i]->GetID() == id)
        {
            check = true;
            break;
        }
    }
    if(check)
    {
        aptr[i]->Withdraw(money);
        cout << "출금완료" << endl;
    }
    else
        cout << "입력한 계좌ID와 일치하는 계좌가 없습니다." << endl;
    cout << endl;
}

void AccountHandler::ShowAllInfo()
{
    cout << "[계좌정보 전체 출력]" << endl;
    for(int i = 0; i < arrIdx; i++)
    {
        aptr[i]->ShowInfo();
    }
    cout << endl;
}

AccountHandler::~AccountHandler()
{
    for(int i = 0; i < arrIdx; i++)
    {
        delete aptr[i];
    }
}
