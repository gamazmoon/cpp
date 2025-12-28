#include <iostream>
using namespace std;

int main()
{
    int x, abs;

    cout << "Enter x:";
    cin >> x;

    abs = x;

    if(x<0){
        abs=-x;
    }

    cout << "|x|: " << abs << "\n";

    return 0;
}