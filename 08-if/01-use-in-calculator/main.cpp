#include <iostream>
using namespace std;

/*
if

*/

int main()
{
    int a, b, z;

    cout << "Enter a:";
    cin >> a;

    cout << "Enter b:";
    cin >> b;

    if (b == 0)
    {
        cout << "Error! Division by Zero.";
    }
    else
    {
        z = a / b;
        cout << "a/b is:" << z << endl;
    }

    return 0;
}