#include <iostream>
using namespace std;

int main()
{
    int x0, x1, x2;
    int max;

    cout << "Enter x0:";
    cin >> x0;

    cout << "Enter x1:";
    cin >> x1;

    cout << "Enter x2:";
    cin >> x2;

    max = x0;

    if (x1 > max)
    {
        max = x1;
    }

    if (x2 > max)
    {
        max = x2;
    }

    cout<<max<<"\n";

    return 0;
}