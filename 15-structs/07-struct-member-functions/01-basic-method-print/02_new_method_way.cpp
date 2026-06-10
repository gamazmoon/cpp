// -----------------------------------------------------------------------------
// فایل سمت راست: رویکرد جدید (تعریف متد یا تابع داخلی)
//
// هدف آموزشی:
// - مشاهده هجرت تابع به درون بدنه Struct.
// - حذف پارامتر ورودی به دلیل دسترسی مستقیم متد به فیلدهای داخلی شیء.
// - تغییر نحوه فراخوانی با استفاده از اپراتور نقطه (myProduct.print).
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    int stock;
    int price;

    void print()
    {
        cout << "ID: " << id << " | Name: " << name
             << " | Stock: " << stock << " | Price: " << price << "\n";
    }
};

int main()
{
    Product myProduct = {101, "Rice", 30, 120};
    Product myProduct2 = {102, "Oil", 25, 125};

    myProduct.print();
    myProduct2.print();

    return 0;
}