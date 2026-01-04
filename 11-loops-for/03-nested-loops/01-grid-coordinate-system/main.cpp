#include <iostream>
using namespace std;

int main()
{
    int num_of_rows;
    int num_of_cols;

    cout << "Enter number of rows:";
    cin >> num_of_rows;

    cout << "Enter number of cols:";
    cin >> num_of_cols;

    for (int i = 1; i <= num_of_rows; i++)
    {
        //----------------
        for (int j = 1; j <= num_of_cols; j++)
        {
            cout << "(" << i << "," << j << ")";
        }

        cout << endl;
        //----------------
    }

    return 0;
}