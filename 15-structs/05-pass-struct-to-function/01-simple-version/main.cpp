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

void printProduct(Product p)
{
    cout << "ID: " << p.id << " | Name: " << p.name
         << " | Stock: " << p.stock << " | Price: " << p.price << "\n";
}

void reduceStock(Product &p, int qty)
{
    p.stock = p.stock - qty;
}

int main()
{
    Product myProduct = {101, "Rice", 30, 120};

    printProduct(myProduct);

    reduceStock(myProduct, 5);

    printProduct(myProduct);

    return 0;
}