#include <iostream>
using namespace std;

/*
تکرار برنامه تا زمان ورود عدد خروج (صفر)
*/

int main()
{
    int number;

    while (true)
    {
        cout << "Enter a number: ";
        cin >> number;

        if (number == 0)
        {
            break;
        }

        int p = number * number;
        cout << "The power is: " << p << endl;
    }

    return 0;
}
