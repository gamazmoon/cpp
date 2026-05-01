#include <iostream>
using namespace std;

int main()
{

    int x[2][3] = {
        {10, 11, 12},
        {20, 21, 22}};

    int i;

    for (i = 0; i < 2; i = i + 1)
    {
        cout << x[i][2] << "\t";
    }

    cout << endl; // \n

    return 0;
}
