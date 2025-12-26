#include <iostream>
using namespace std;

int main()
{
    // 1) Simple Assignment: Initializes x with a value
    int x = 11;
    cout << "1) Initial value: " << x << "\n";

    // 2) Reassignment: Overwrites the old value (11) with a new one
    x = 100;
    cout << "2) After reassignment: " << x << "\n";

    // 3) Update Assignment: Uses the current value to calculate a new one
    // Logic: "New value of x = Old value of x (100) + 1"
    x = x + 1;
    cout << "3) After x = x + 1: " << x << "\n";

    // 4) Compound Assignment: Shorthand for updating variables
    x += 5; // Equivalent to x = x + 5
    cout << "4) After x += 5: " << x << "\n";

    // 5) Increment Operator: Specifically adds 1
    x++; // Equivalent to x = x + 1
    cout << "5) After x++: " << x << "\n";

    return 0;
}