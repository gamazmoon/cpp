#include <iostream>
using namespace std;

int main()
{
    double score;
    cout << "لطفاً نمره خود را وارد کنید (0-20): ";
    cin >> score;

    // ۱) ابتدا بررسی نمرات نامعتبر (فیلتر اولیه)
    if (score < 0 || score > 20)
    {
        cout << "Invalid Score!" << "\n";
    }
    else
    {
        // ۲) حالا که مطمئن هستیم نمره بین 0 تا 20 است، دسته‌بندی را انجام می‌دهیم

        // بازه نمره A
        if (score >= 17 && score <= 20)
        {
            cout << "Grade: A" << "\n";
        }

        // بازه نمره B
        if (score >= 14 && score < 17)
        {
            cout << "Grade: B" << "\n";
        }

        // بازه نمره C
        if (score >= 12 && score < 14)
        {
            cout << "Grade: C" << "\n";
        }

        // بازه نمره D
        if (score >= 10 && score < 12)
        {
            cout << "Grade: D" << "\n";
        }

        // بازه نمره F
        if (score >= 0 && score < 10)
        {
            cout << "Grade: F" << "\n";
        }
    }

    return 0;
}