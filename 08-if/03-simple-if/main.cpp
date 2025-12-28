#include <iostream>
using namespace std;

int main()
{
    // Declare a variable and set it a value less than 10
    int number = 5;
    // If the value of number is less than 10
    if (number < 10)
    {
        cout << "Hello World." << endl;
    }

    // Change the value of a number to a value which is greater than 10
    number = 15;
    // If the value of number is greater than 10
    if (number > 10)
    {
        cout << "Goodbye World.";
    }

    return 0;
}