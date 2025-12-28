#include <iostream>
using namespace std;

/*
یک ماشین حساب ساده
دریافت اعداد از کاربر
*/

int main()
{
    int a, b, z;

    cout<<"Enter a:";
    cin >> a;

    cout<<"Enter b:";
    cin >> b;

    z = a * b;
    cout << "a*b is:" << z << endl;

    z = a / b;
    cout << "a/b is:" << z << endl;

    z = a + b;
    cout << "a+b is:" << z << endl;

    z = a - b;
    cout << "a-b is:" << z << endl;

    return 0;
}