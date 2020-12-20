//
//  AccountArray.cpp
//  Q11-4 (Banking_v0.8)
//
//  Created by songhee on 2020/12/19.
//

#include "AccountArray.hpp"
#include "BankingCommonDecl.hpp"

#include <iostream>
#include <cstdlib>
using namespace std;

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(len)
{
    arr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    
    return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[] (int idx) const
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    
    return arr[idx];
}
int BoundCheckAccountPtrArray::GetArrLen() const
{
    return arrlen;
}
BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
    delete []arr;
}
