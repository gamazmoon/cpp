#include <iostream>
using namespace std;

/*
جا به جایی مقدار دو متغیر
*/

int main()
{
    int a = 10, b = 20, t;

    t = a;
    a = b;
    b = t;

    cout << a << "\n";
    cout << b << "\n";

    return 0;
}