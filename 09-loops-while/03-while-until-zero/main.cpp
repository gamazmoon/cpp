#include <iostream>
using namespace std;

/*
تکرار برنامه تا زمان ورود عدد خروج (صفر)
*/

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    while (number != 0)
    {
        int p = number * number;
        cout << "The power is: " << p << "\n";

        cout << "Enter a number: ";
        cin >> number;
    }

    cout << "--- Program finished. Goodbye! ---" << "\n";
    return 0;
}
