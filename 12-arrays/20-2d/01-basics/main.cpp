#include <iostream>
using namespace std;

int main()
{

    int x[2][3];
    int i, j;

    for (i = 0; i < 2; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            cout << "Please enter (" << i + 1 << "," << j + 1 << "): ";
            cin >> x[i][j];
        }
    }

    for (i = 0; i < 2; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            cout<< x[i][j]<<"\t";
        }
        cout<<endl;// const char endl='\n';

    }

    return 0;
}
