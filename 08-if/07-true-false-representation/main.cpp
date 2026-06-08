#include <iostream>
using namespace std;

int main()
{
    // Part 1: How C++ stores Boolean keywords
    cout << "Value of true  : " << true << "\n";  // Output: 1
    cout << "Value of false : " << false << "\n"; // Output: 0
    cout << "---------------------------------------" << "\n";

    // Part 2: Testing Integer values in Boolean context
    cout << "--- Part 2: Integer to Boolean Logic ---" << "\n";

    // A positive number
    if (10)
    {
        cout << "10 is treated as true." << "\n";
    }

    // A negative number
    if (-5)
    {
        cout << "-5 is also treated as true." << "\n";
    }

    // The only value that is false
    if (0)
    {
        cout << "This line will NOT be printed." << "\n";
    }
    else
    {
        cout << "0 is the only value treated as false." << "\n";
    }

    return 0;
}