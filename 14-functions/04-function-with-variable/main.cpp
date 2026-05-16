#include <iostream>
using namespace std;

int f()
{
    int a = 10;
    return a;
}

int main()
{
    int a;

    a = f();
    
    cout << a;

    return 0;
}
