//
//  Point.hpp
//  Q13-2_0
//
//  Created by songhee on 2020/12/22.
//

#ifndef Point_hpp
#define Point_hpp

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
    friend ostream& operator<<(ostream& os, const Point& pos);
};

#endif /* Point_hpp */
