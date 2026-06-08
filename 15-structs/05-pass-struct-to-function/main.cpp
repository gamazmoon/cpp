// -----------------------------------------------------------------------------
// مثال: ارسال Struct به تابع (به صورت کپی و ارجاع)
//
// هدف آموزشی:
// - یادگیری روش‌های ارسال یک Struct به تابع (Pass by Value vs Pass by Reference)
// - پیاده‌سازی دو سناریو: ۱) تابع چاپ اطلاعات کالا  ۲) تابع کاهش موجودی کالا
//
// نکته آموزشی مهم برای کلاس:
// ۱) در تابع printProduct، شیء به صورت معمولی (Value) ارسال شده است. یعنی کل ساختار
//    در حافظه کپی می‌شود. در متن درس اشاره کنید که برای بهینه‌سازی حافظه، بهتر است
//    ساختارهای بزرگ را با ارجاع ثابت (const Product &p) بفرستیم تا کپی نشوند.
// ۲) در تابع reduceStock، شیء با ارجاع (&) ارسال شده تا تغییرات مستقیماً روی کالا اعمال شود.
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

// ۱) تابع نمایش اطلاعات کالا (ارسال به صورت کپی / Pass by Value)
// این تابع فقط برای چاپ است و تغییری در شیء اصلی ایجاد نمی‌کند.
// -----------------------------------------------------------------------------
void printProduct(Product p)
{
    cout << "ID: " << p.id << " | Name: " << p.name
         << " | Stock: " << p.stock << " | Price: " << p.price << "\n";
}

// ۲) تابع کاهش موجودی کالا (ارسال به صورت مرجع / Pass by Reference)
// -----------------------------------------------------------------------------
bool reduceStock(Product &p, int qty)
{
    if (qty <= 0)
        return false;

    if (p.stock >= qty)
    {
        p.stock = p.stock - qty; // تغییر مستقیم روی شیء اصلی در حافظه
        return true;
    }
    return false;
}

int main()
{
    Product myProduct = {101, "Rice", 30, 120};

    printProduct(myProduct);

    reduceStock(myProduct, 5);

    return 0;
}