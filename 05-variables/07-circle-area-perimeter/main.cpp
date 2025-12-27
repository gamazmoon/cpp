#include <iostream>
using namespace std;

/*
محاسبه مساحت و محیط یک دایره با شعاع ۳
*/

int main()
{
    // تعریف متغیرها
    const double PI = 3.14159;
    double radius = 3; //شعاع دایره
    double area, perimeter;

    cout << "برنامه محاسبه مساحت و محیط دایره" << endl;
    cout << "--------------------------------" << endl;

    // محاسبات
    area = PI * radius * radius;
    perimeter = 2 * PI * radius;

    // نمایش خروجی
    cout << "مساحت دایره: " << area << endl;
    cout << "محیط دایره: " << perimeter << endl;

    return 0;
}