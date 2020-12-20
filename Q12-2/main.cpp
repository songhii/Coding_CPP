//
//  main.cpp
//  Q12-2
//
//  Created by songhee on 2020/12/19.
//

#include <iostream>
#include <cstring>
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

String::String()
: len(0), str(NULL)
{ }

String::String(const char* s)
: len(strlen(s)+1)
{
    str = new char[len];
    strcpy(str, s);
}

String::String(const String& s)
: len(s.len)
{
    str = new char[len];
    strcpy(str, s.str);
}

String& String::operator=(const String& s)
{
    if(str != NULL)
        delete []str;
    len = s.len;
    str = new char[len];
    strcpy(str, s.str);
    
    return *this;
}

String String::operator+(const String& s)
{
    char* tmp = new char[len+s.len-1];
    strcpy(tmp, str);
    strcat(tmp, s.str);
    
    String str_tmp(tmp);
    delete []tmp;
    
    return str_tmp;
}

String& String::operator+=(const String& s)
{
    len += (s.len-1);
    
    char* tmp = new char[len];
    strcpy(tmp, str);
    strcat(tmp, s.str);
    
    if(str != NULL)
        delete []str;
    
    str = tmp;

    return *this;
}

bool String::operator==(const String& s)
{
    if(!strcmp(str, s.str))
        return true;
    else
        return false;
}

String::~String()
{
    if(str != NULL)
        delete []str;
}

ostream& operator<<(ostream& os, const String& s)
{
    os << s.str;
    return os;
}

istream& operator>>(istream& is, String& s)
{
    char tmp[100];
    is >> tmp;
    s = String(tmp);
    
    return is;
}

int main(void)
{
    String str1="I like ";
    String str2="string class";
    String str3=str1+str2;

    cout<<str1<<endl;
    cout<<str2<<endl;
    cout<<str3<<endl;
    
    str1+=str2;
    if(str1==str3)
        cout<<"동일 문자열!"<<endl;
    else
        cout<<"동일하지 않은 문자열!"<<endl;

    String str4;
    cout<<"문자열 입력: ";
    cin>>str4;
    cout<<"입력한 문자열: "<<str4<<endl;
    
    return 0;
}
