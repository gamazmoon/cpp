#include <iostream>
using namespace std;

int main()
{
    int number = 5;
    // Test the condition
    if (number < 10)
    {
        cout << "The number is less than 10." << endl;
    }
    else
    {
        cout << "The number is either greater than or equal to 10." << endl;
    }
    
    // Modify value of number
    number = 15;
    // Repeat the test to yield a different result
    if (number < 10)
    {
        cout << "The number is less than 10." << endl;
    }
    else
    {
        cout << "The number is either greater than or equal to 10." << endl;
    }

    return 0;
}