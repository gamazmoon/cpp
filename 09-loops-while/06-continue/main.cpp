#include <iostream>
using namespace std;

/*
تکرار برنامه تا زمان ورود عدد خروج (صفر)
مستثنی کردن یک وردی خاص. مثلا عدد های منفی
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

        if (number < 0)
        {
            continue;
        }

        int p = number * number * number;
        cout << "The power is: " << p << endl;
    }

    return 0;
}
