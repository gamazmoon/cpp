#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int z;

    cout << "Enter a:";
    cin >> a;

    do
    {
        cout << "Enter b:";
        cin >> b;
    } while (b == 0);

    z = a / b;
    cout << "a/b is:" << z << endl;

    return 0;
}