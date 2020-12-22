//
//  Point.cpp
//  Q13-2_0
//
//  Created by songhee on 2020/12/22.
//

#include "Point.hpp"

ostream& operator<<(ostream& os, const Point& pos)
{
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
