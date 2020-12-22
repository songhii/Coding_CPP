//
//  main.cpp
//  Q12-2
//
//  Created by songhee on 2020/12/19.
//

#include <iostream>
#include <cstring>
#include "BankingCommonDecl.hpp"
using namespace std;

class String
{
private:
    int len;
    char* str;
    
public:
    String();
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String operator+(const String&);
    String& operator+=(const String&);
    bool operator==(const String&);
    ~String();
    
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
};
