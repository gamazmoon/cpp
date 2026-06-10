// -----------------------------------------------------------------------------
// فایل سمت چپ: رویکرد قدیمی (ارسال ساختار به تابع عمومی)
//
// هدف آموزشی:
// - یادآوری نحوه استفاده از تابع بیرونی برای پردازش اطلاعات Struct.
// - توجه به این نکته که تابع برای دسترسی به داده‌ها مجبور است کل شیء را ورودی بگیرد.
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
};

void printProduct(Product p)
{
    cout << "ID: " << p.id << " | Name: " << p.name 
         << " | Stock: " << p.stock << " | Price: " << p.price << "\n";
}

int main()
{
    Product myProduct = {101, "Rice", 30, 120};

    printProduct(myProduct); 

    return 0;
}