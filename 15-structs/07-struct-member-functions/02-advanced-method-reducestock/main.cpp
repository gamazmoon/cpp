// -----------------------------------------------------------------------------
// مثال: متدها یا توابع داخلی ساختار (Member Functions)
//
// هدف آموزشی:
// - یادگیری نحوه تعریف تابع درون بدنه یک Struct (مفهوم کپسوله‌سازی منطق).
// - درک تفاوت فراخوانی متدها با توابع عمومی (استفاده از اپراتور نقطه: p.print).
// - حذف نیاز به ارسال ارجاع (&)؛ چون متد داخلی مستقیماً به اعضای خودِ شیء دسترسی دارد.
//
// مقایسه با بخش ۵:
// به دانشجو نشان دهید که چگونه توابع printProduct و reduceStock از خارج ساختار به
// داخل آن منتقل شده‌اند و کد چقدر منظم‌تر و خواناتر شده است.
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// تعریف ساختار کالا به همراه رفتارهای آن (متدها)
struct Product
{
    // ۱) اعضا یا فیلدهای داده‌ای (Data Members)
    int id;
    string name;
    int stock;
    int price;

    // ۲) متد داخلی نمایش اطلاعات (چون درون struct است به تمام فیلدها دسترسی مستقیم دارد)
    void print() const
    {
        cout << "ID: " << id << " | Name: " << name
             << " | Stock: " << stock << " | Price: " << price << "\n";
    }

    // ۳) متد داخلی کاهش موجودی کالا (به تغییر مستقیم فیلد stock بدون نیاز به & دقت کنید)
    bool reduceStock(int qty)
    {
        if (qty <= 0)
        {
            return false;
        }

        if (stock < qty)
        {
            return false;
        }

        stock = stock - qty; // تغییر روی موجودی همین شیء اعمال می‌شود
        return true;
    }
};

int main()
{
    // تعریف شیء کالا
    Product myProduct = {101, "Rice", 30, 120};

    cout << "--- Display via Method ---\n";
    myProduct.print(); // فراخوانی متد داخلی شیء

    int qty;
    cout << "\nEnter quantity to order: ";
    cin >> qty;

    // صدا زدن متد کاهش موجودی روی خودِ شیء
    if (myProduct.reduceStock(qty))
    {
        cout << "Order accepted.\n";
        cout << "--- Updated Info via Method ---\n";
        myProduct.print();
    }
    else
    {
        cout << "Order rejected. Not enough stock.\n";
    }

    return 0;
}