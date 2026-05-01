#include <iostream>
using namespace std;

int main()
{

    int x[2][3] = {
        {10, 11, 12},
        {20, 21, 22}};

    int i, j;

    int sum = 0;
    for (i = 0; i < 2; i = i + 1)
    {
        for (j = 0; j < 3; j = j + 1)
        {
            sum = sum + x[i][j];
        }
    }

    cout<<"Sum is:"<<sum<<endl;
    cout<<"Avg is:"<<sum/(2*3)<<endl;

    return 0;
}
