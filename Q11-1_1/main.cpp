//
//  main.cpp
//  Q11-1_1
//
//  Created by songhee on 2020/12/17.
//

#include <iostream>
#include <cstring>
using namespace std;

class Police;

class Gun
{
private:
    int bullet;        // 장전된 총알의 수
public:
    Gun(int bnum) : bullet(bnum)
    {
        cout << "Gun(int bnum)" << endl;
    }
//    Gun(Gun& pis)
//    {
//        cout << "Gun(Gun& pis)" << endl;
//    }
    
    void Show()
    {
        cout << "bullet : " << bullet;
    }
    
    void Shut()
    {
        cout<<"BBANG!"<<endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;    // 소유한 수갑의 수
    Gun * pistol;     // 소유하고 있는 권총
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        cout << "Police(int bnum, int bcuff)" << endl;
        if(bnum>0)
            pistol=new Gun(bnum);
        else
            pistol=NULL;
    }
    
    Police(Police& ref)
    : handcuffs(ref.handcuffs)
    {
        cout << "Police(Police& ref)" << endl;
        if(ref.pistol != NULL)
        {
            pistol = new Gun(*(ref.pistol));
        }
        else
        {
            pistol = NULL;
        }
    }
//
    Police& operator=(Police& ref)
    {
        cout << "operator=(Police& ref)" << endl;
        
        handcuffs = ref.handcuffs;
        
        if(pistol != NULL)
            delete pistol;
        
        if(ref.pistol != NULL)
        {
            pistol = new Gun(*(ref.pistol)); //*(ref.pistol) : Gun 객체 자체 의미
//            cout << "### *(ref.pistol) : " << ref.pistol << endl;
        }
        else
        {
            pistol = NULL;
        }
        return *this;
    }
    
    void Show()
    {
        if(pistol != NULL)
        {
            pistol->Show();
        }
        else
        {
            cout << "bullet : 0";
        }
        cout << " / cuffs : " << handcuffs << endl;
    }
    
    void PutHandcuff()
    {
        cout<<"SNAP!"<<endl;
        handcuffs--;
    }
    void Shut()
    {
        if(pistol==NULL)
            cout<<"Hut BBANG!"<<endl;
        else
            pistol->Shut();
    }
    ~Police()
    {
        if(pistol!=NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman1(5, 3);
    Police pman2 = pman1;
    pman1.Show();
    pman2.Show();
    Police pman3(2, 4);
    pman3.Show();
    pman3 = pman1;
    pman3.Show();
    return 0;
}
