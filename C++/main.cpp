#include <iostream>
using namespace std;

int main(void)
{
    int money = 1000;
    double interest = 30 * 0.01;
    money += (money * interest);
    cout << money << endl;
    return 0;
}
