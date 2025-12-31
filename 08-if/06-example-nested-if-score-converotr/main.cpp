#include <iostream>
using namespace std;

int main()
{
    double score;
    cout << "لطفاً نمره خود را وارد کنید: ";
    cin >> score;

    // ۱) ابتدا بررسی نمرات منفی
    if (score < 0)
    {
        cout << "نمره نامعتبر است (کمتر از صفر)." << endl;
    }
    else
    {
        // ۲) بررسی نمرات مردود (بین ۰ تا ۱۰)
        if (score < 10)
        {
            cout << "رتبه شما: F (مردود)" << endl;
        }
        else
        {
            // ۳) بررسی نمره ۱۰ تا ۱۲
            if (score < 12)
            {
                cout << "رتبه شما: D" << endl;
            }
            else
            {
                // ۴) بررسی نمره ۱۲ تا ۱۴
                if (score < 14)
                {
                    cout << "رتبه شما: C" << endl;
                }
                else
                {
                    // ۵) بررسی نمره ۱۴ تا ۱۷
                    if (score < 17)
                    {
                        cout << "رتبه شما: B" << endl;
                    }
                    else
                    {
                        // ۶) بررسی نمره ۱۷ تا ۲۰
                        if (score <= 20)
                        {
                            cout << "رتبه شما: A" << endl;
                        }
                        else
                        {
                            // ۷) نمرات بالای ۲۰
                            cout << "نمره نامعتبر است (بیشتر از ۲۰)." << endl;
                        }
                    }
                }
            }
        }
    }

    return 0;
}