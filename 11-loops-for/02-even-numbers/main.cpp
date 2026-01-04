#include <iostream>
using namespace std;

int main()
{
    int i;

    for (i = 1; i <= 4; i++)
    {
        cout << i * 2 << "\t";
    }
    cout << "\n---------------\n";

    for (i = 1; i <= 8; i++)
    {
        if (i % 2 == 1) // عدد فرد است
        {
            continue;
        }
        cout << i << "\t";
    }

    cout << "\n---------------\n";

    for (i = 2; i <= 8; i += 2)
    {
        cout << i << "\t";
    }

    return 0;
}