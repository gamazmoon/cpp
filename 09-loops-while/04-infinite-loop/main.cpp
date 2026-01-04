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
        cout << "The power is: " << p << endl;

        cout << "Enter a number: ";
        cin >> number;
    }

    cout << "--- Program finished. Goodbye! ---" << endl;
    return 0;
}
