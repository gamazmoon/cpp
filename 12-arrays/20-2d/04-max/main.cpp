#include <iostream>
using namespace std;

int main()
{

    int x[2][3] = {
        {10, 11, 12},
        {20, 21, 22}};

    int i, j;

    int indI = 0;
    int indJ = 0;
    int max = x[0][0];
    
    for (i = 0; i < 2; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            if (x[i][j] > max)
            {
                max = x[i][j];
                indI = i;
                indJ = j;
            }
        }
    }

    cout << "Max in (" << indI << "," << indJ << ")" << endl;
    cout << "Max is:" << max;

    return 0;
}
