#include <iostream>
using namespace std;

int main()
{
    int counter = 8;
    while (counter >= 2)
    {
        cout << "H" << counter << endl;

        counter -= 2;
    }

    cout << counter;
    return 0;
}