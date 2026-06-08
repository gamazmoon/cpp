#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 5;
    bool is_ready = true;

    cout << "true && 5 < 3     : " << (true && 5 < 3) << "\n";
    cout << "10 == 10 || false : " << (10 == 10 || false) << "\n";
    cout << "--------------------------\n";

    cout << "x > y && is_ready : " << (x > y && is_ready) << "\n";
    cout << "!is_ready         : " << (!is_ready) << "\n";
    cout << "--------------------------\n";

    // الف) متغیر با عدد ثابت
    bool check1 = (x > 100 || false);
    cout << "x > 100 || false  : " << check1 << "\n";

    cout << "(x == 10 && y > 2): " << (x == 10 && y > 2) << "\n";

    cout << "!(x < y)          : " << (!(x < y)) << "\n";

    bool is_x_big = x > 100;
    cout << "4) Using bool var: " << (is_x_big && true) << "\n";

    return 0;
}