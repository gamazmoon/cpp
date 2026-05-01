#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int *p1 = &x;

    cout << p1;
    cout << endl;

    double d = 14.5;
    double *p2 = &d;

    char c = 'a';
    char *p3 = &c;

    long l = 12334455;
    long*      p4 = &l;

    return 0;
}
