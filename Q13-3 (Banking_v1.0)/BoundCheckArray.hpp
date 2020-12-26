//
//  BoundCheckArray.hpp
//  Q13-3 (Banking_v1.0)
//
//  Created by songhee on 2020/12/23.
//

#ifndef BoundCheckArray_hpp
#define BoundCheckArray_hpp

#include <iostream>
using namespace std;

template <class T>
class BoundCheckArray
{
private:
    T * arr;
    int arrlen;

    BoundCheckArray(const BoundCheckArray& arr) { }
    BoundCheckArray& operator=(const BoundCheckArray& arr) { }

public:
    BoundCheckArray(int len = 100) :arrlen(len)
    {
        arr=new T[len];
    }
    T& operator[] (int idx)
    {
        if(idx<0 || idx>=arrlen)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        
        return arr[idx];
    }
    T operator[] (int idx) const
    {
        if(idx<0 || idx>=arrlen)
        {
            cout<<"Array index out of bound exception"<<endl;
            exit(1);
        }
        
        return arr[idx];
    }
    int GetArrLen() const
    {
        return arrlen;
    }
    ~BoundCheckArray()
    {
        delete []arr;
    }
};

#endif /* BoundCheckArray_hpp */
