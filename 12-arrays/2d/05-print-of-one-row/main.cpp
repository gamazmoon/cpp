#include <iostream>
using namespace std;

int main()
{

    int x[2][3] = {
        {10, 11, 12},
        {20, 21, 22}
    };

    int j;

    for (j = 0; j < 3; j = j + 1)
    {
        cout << x[1][j] << "\t";
    }

    cout << endl; // \n

    return 0;
}
