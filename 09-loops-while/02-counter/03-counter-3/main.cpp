#include <iostream>
using namespace std;

int main()
{
    int counter = 1;
    while (counter <= 4)
    {
        int a = counter * 2;
        cout << "H" << a << endl;

        counter++;
    }

    cout << counter;
    return 0;
}