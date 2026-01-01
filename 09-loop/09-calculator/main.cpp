#include <iostream>
using namespace std;

/*
یک ماشین حساب ساده
*/

int main()
{
    int a, b;
    int z;

    cout << "Enter a:";
    cin >> a;

    cout << "Enter b:";
    cin >> b;

    while (b == 0)
    {
        cout << "Error! Division by Zero.";

        cout << "Enter b agin:";
        cin >> b;
    }

    z = a / b;
    cout << "a/b is:" << z << endl;

    return 0;
}