#include <iostream>
using namespace std;

int main()
{
    int x = 11, y = 5;

    // 1) Multiplication: Standard arithmetic
    cout << "1) multiplication\n";
    cout << 3 * 30 << "\n";  // Literal multiplication (90)
    cout << 2 * y << "\n";   // Constant multiplied by variable (10)
    cout << x * y << "\n\n"; // Variable multiplied by variable (55)

    // 2) Division: Note the difference between Integer and Double results
    cout << "2) division\n";
    cout << 11 / 5 << "\n";   // Integer division: truncates decimal (Result: 2)
    cout << 11 / 5.0 << "\n"; // Floating-point division: 5.0 forces a double result (Result: 2.2)
    cout << x / y << "\n\n";  // Integer variables: results in an integer (Result: 2)

    // 3) Modulus: Returns the remainder of a division
    cout << "3) mod\n";
    cout << 11 % 5 << "\n"; // 11 divided by 5 is 2 with a remainder of 1
    cout << x % y << "\n";  // Remainder of 11 / 5 (Result: 1)

    return 0;
}
