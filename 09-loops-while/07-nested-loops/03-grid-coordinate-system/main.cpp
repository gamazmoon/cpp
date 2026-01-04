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

    int i = 1;
    while (i <= num_of_rows)
    {
        //----------------
        int j = 1;
        while (j <= num_of_cols)
        {
            cout << "("<<i<<","<<j<<")";

            j++;
        }
        cout << endl;
        //----------------

        i++;
    }

    return 0;
}