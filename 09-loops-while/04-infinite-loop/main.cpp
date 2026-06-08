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

    while (true)
    {
        int p = number * number;
        cout << "The power is: " << p << "\n";

        cout << "Enter a number: ";
        cin >> number;
    }

    cout << "--- Program finished. Goodbye! ---" << "\n";
    return 0;
}
