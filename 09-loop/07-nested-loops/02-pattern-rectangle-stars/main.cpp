#include <iostream>
using namespace std;

int main()
{
    int num_of_rows = 3;
    int num_of_cols = 5;

    int i = 1;
    while (i <= num_of_rows)
    {
        //----------------
        int j = 1;
        while (j <= num_of_cols)
        {
            cout << "*";

            j++;
        }
        cout << endl;
        //----------------

        i++;
    }

    return 0;
}