//
//  main.cpp
//  Q02-1_3
//
//  Created by songhee on 2020/11/27.
//

#include <iostream>
using namespace std;

void SwapPointer(int *(&pref1), int *(&pref2)) {
    int *tmp = pref2;
    pref2 = pref1;
    pref1 = tmp;
}

int main(int argc, const char * argv[]) {
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;
    
    cout << *ptr1 << " " << *ptr2 << endl;
    SwapPointer(ptr1, ptr2);
    cout << *ptr1 << " " << *ptr2 << endl;
 
    return 0;
}
