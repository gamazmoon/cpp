#include <iostream>
using namespace std;

int main()
{
    const int NUM_ROW = 2;
    const int NUM_COL = 3;

    int x[NUM_ROW][NUM_COL];
    int i, j;

    for (i = 0; i < NUM_ROW; i = i + 1)
    {
        for (j = 0; j < NUM_COL; j = j + 1)
        {
            cout << "Please enter (" << i + 1 << "," << j + 1 << "): ";
            cin >> x[i][j];
        }
    }

    for (i = 0; i < NUM_ROW; i = i + 1)
    {
        for (j = 0; j < NUM_COL; j = j + 1)
        {
            cout << x[i][j] << "\t";
        }
        cout << endl; // \n
    }

    return 0;
}
