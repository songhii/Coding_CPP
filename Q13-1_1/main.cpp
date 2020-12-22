//
//  main.cpp
//  Q13-1_1
//
//  Created by songhee on 2020/12/22.
//

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
    
public:
    Point(int x=0, int y=0)
    : xpos(x), ypos(y)
    { }
    
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
};

template <class T>
void SwapData(T& n1, T& n2)
{
    T temp = n1;
    n1 = n2;
    n2 = temp;
}

int main(int argc, const char * argv[]) {
    Point pos1(3, 4);
    Point pos2(10, 20);
    
    SwapData(pos1, pos2);
    
    pos1.ShowPosition();
    pos2.ShowPosition();
    
    return 0;
}
