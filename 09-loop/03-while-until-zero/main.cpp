#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;

    while (number != 0)
    {
        int p = number * number;
        cout << "The power is: " << p << endl;

        cout << "Enter a number: ";
        cin >> number;
    }

    cout << "--- Program finished. Goodbye! ---" << endl;
    return 0;
}

// تکرار برنامه تا زمان ورود عدد خروج (صفر)