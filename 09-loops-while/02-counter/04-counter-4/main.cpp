#include <iostream>
using namespace std;

int main()
{
    int counter = 2;
    while (counter <= 8)
    {
        cout << "H" << counter << endl;

        counter += 2;
    }

    cout << counter;
    return 0;
}