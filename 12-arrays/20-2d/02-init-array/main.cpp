#include <iostream>
using namespace std;

int main()
{

    int a[4]={17,2,12,4};

    int x[2][3] = {
        {10, 11, 12},
        {20, 21, 22}
        };

    int i, j;

    for (i = 0; i < 2; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            cout << x[i][j]<< "\t" ;
        }
        
        cout << endl; // \n
    }

    return 0;
}
