//
//  AccountArray.hpp
//  Q11-4 (Banking_v0.8)
//
//  Created by songhee on 2020/12/19.
//

#ifndef AccountArray_hpp
#define AccountArray_hpp

#include "Account.hpp"

#include <iostream>
#include <cstdlib>
using namespace std;

typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
    ACCOUNT_PTR* arr;
    int arrlen;

    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) { }
    BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {return *this;}

public:
    BoundCheckAccountPtrArray(int len = 100);
    ACCOUNT_PTR& operator[] (int idx);
    ACCOUNT_PTR operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckAccountPtrArray();
};

#endif /* AccountArray_hpp */
