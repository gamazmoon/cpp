#include <iostream>
using namespace std;

int main()
{
    double score;
    cout << "Enter your score (0-20): ";
    cin >> score;

    // ۱) بررسی سقف نمره (بیشتر از ۲۰ نباشد)
    if (score > 20)
    {
        cout << "Invalid: Score cannot be greater than 20)" << endl;
    }
    else
    {
        // ۲) حالا نمره ۲۰ یا کمتر است، رتبه‌ها را چک می‌کنیم
        if (score >= 17)
        {
            cout << "Grade: A (Excellent)" << endl;
        }
        else
        {
            // ۳) اگر به اینجا برسیم یعنی نمره قطعا کمتر از ۱۷ است
            if (score >= 14)
            {
                cout << "Grade: B (Good)" << endl;
            }
            else
            {
                // ۴) اگر به اینجا برسیم یعنی نمره قطعا کمتر از ۱۴ است
                if (score >= 12)
                {
                    cout << "Grade: C (Average)" << endl;
                }
                else
                {
                    // ۵) اگر به اینجا برسیم یعنی نمره قطعا کمتر از ۱۲ است
                    if (score >= 10)
                    {
                        cout << "Grade: D (Passing)" << endl;
                    }
                    else
                    {
                        // ۶) حالا باید بین نمره منفی و مردود تفکیک قائل شویم
                        if (score >= 0)
                        {
                            cout << "Grade: F (Fail)" << endl;
                        }
                        else
                        {
                            // ۷) نمرات کمتر از صفر
                            cout << "Invalid: Score cannot be less than 0." << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}