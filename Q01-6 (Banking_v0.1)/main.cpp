//
//  main.cpp
//  Q01-6
//
//  Created by songhee on 2020/11/27.
//

#include <iostream>
#include <cstring>
#define NAME_LEN 30
using namespace std;

struct Account {
    int ID;
    char name[NAME_LEN];
    int balance;
};

int arrIdx = 0;
Account arr[100];

void showMenu()
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void create()
{
    int id;
    char name[NAME_LEN];
    int bal;
    
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> bal;
    cout << endl;
    
    arr[arrIdx].ID = id;
    strcpy(arr[arrIdx].name, name);
    arr[arrIdx++].balance = bal;
}

void deposit()
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
        if(arr[i].ID == id)
        {
            check = true;
            break;
        }
    }
    if(check)
    {
        arr[i].balance += money;
        cout << "입금완료" << endl;
    }
    else
        cout << "입력한 계좌ID와 일치하는 계좌가 없습니다." << endl;
    cout << endl;
}

void withdraw()
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
        if(arr[i].ID == id)
        {
            check = true;
            break;
        }
    }
    if(check)
    {
        if(arr[i].balance >= money)
        {
        arr[i].balance -= money;
        cout << "출금완료" << endl;
        }
        else
        {
            cout << "잔액이 부족합니다. (출금액: " << money << " > 잔액: " << arr[i].balance << ")" << endl;
        }
    }
    else
        cout << "입력한 계좌ID와 일치하는 계좌가 없습니다." << endl;
    cout << endl;
}

void show()
{
    cout << "[계좌정보 전체 출력]" << endl;
    for(int i = 0; i < arrIdx; i++)
    {
        cout << "계좌ID: " << arr[i].ID << endl;
        cout << "이 름: " << arr[i].name << endl;
        cout << "잔 액: " << arr[i].balance << endl;
        cout << endl;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    int opt;
    
    while(1) {
        showMenu();
        cout << "선택: ";
        cin >> opt;
        cout << endl;
        
        switch(opt)
        {
            case 1:
                create();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                show();
                break;
            case 5:
                return 0;
        }
        
    }
    return 0;
}
