#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 5;
    bool is_ready = true;

    cout << "true && 5 < 3     : " << (true && 5 < 3) << endl;
    cout << "10 == 10 || false : " << (10 == 10 || false) << endl;
    cout << "--------------------------\n";

    cout << "x > y && is_ready : " << (x > y && is_ready) << endl;
    cout << "!is_ready         : " << (!is_ready) << endl;
    cout << "--------------------------\n";

    // الف) متغیر با عدد ثابت
    bool check1 = (x > 100 || false);
    cout << "x > 100 || false  : " << check1 << endl;

    cout << "(x == 10 && y > 2): " << (x == 10 && y > 2) << endl;

    cout << "!(x < y)          : " << (!(x < y)) << endl;

    bool is_x_big = x > 100;
    cout << "4) Using bool var: " << (is_x_big && true) << endl;

    return 0;
}