#include <iostream>
using namespace std;

int main()
{
    int x, abs;

    cout << "Enter x:";
    cin >> x;

    if (0 <= x)
    {//+
        abs = x;
    }
    else
    {//-
        abs = -x;
    }

    cout << "|x|: " << abs << "\n";

    return 0;
}