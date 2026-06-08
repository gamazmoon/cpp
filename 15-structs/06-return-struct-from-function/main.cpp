// -----------------------------------------------------------------------------
// مثال: بازگرداندن ساختار از تابع (Return Struct)
//
// هدف آموزشی:
// - درک این مفهوم که Struct یک نوع داده (Type) معتبر در زبان ++C است.
// - یادگیری نحوه تعریف توابعی که خروجی آن‌ها یک ساختار کامل است.
// - آشنایی با الگوی ساخت یا کارخانه (Factory) برای تولید یک شیء جدید بر اساس داده‌های ورودی.
//
// سناریوی پروژه:
// طراحی یک تابع که یک کالای اصلی را می‌گیرد و یک کالای جدید تشویقی (Promo) با قیمت 
// تخفیف‌خورده تولید کرده و به عنوان خروجی تابع بازمی‌گرداند.
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

// -----------------------------------------------------------------------------
// تابع تولید کالای تخفیف‌خورده
// ورودی: کالای اصلی (به صورت ارجاع خواندنی برای سرعت) و درصد تخفیف
// خروجی: یک شیء ساختار کاملاً جدید و مستقل از نوع Product
// -----------------------------------------------------------------------------
Product createDiscountedProduct(const Product &original, int discountPercentage)
{
    Product promoProduct; // تعریف یک شیء محلی جدید درون تابع

    promoProduct.id = original.id + 1000; // تولید یک شناسه خاص برای کالاهای تخفیفی
    promoProduct.name = original.name + " (Promo)";
    promoProduct.stock = original.stock;  // موجودی همان موجودی قبلی است
    
    // محاسبه قیمت جدید پس از کسر درصد تخفیف
    promoProduct.price = original.price * (100 - discountPercentage) / 100;

    return promoProduct; // بازگرداندن کل ساختار به عنوان خروجی
}

int main()
{
    // ۱) تعریف کالای اصلی
    Product p1 = {101, "Rice", 30, 120};

    // ۲) فراخوانی تابع و ذخیره ساختار خروجی در یک متغیر جدید
    Product p2 = createDiscountedProduct(p1, 20); // اعمال ۲۰ درصد تخفیف

    // ۳) نمایش نتایج برای اثبات خلق شیء جدید با مشخصات متفاوت
    cout << "=== Original Product ===\n";
    cout << "ID: " << p1.id << " | Name: " << p1.name << " | Price: " << p1.price << "\n";

    cout << "\n=== New Discounted Product (Returned from function) ===\n";
    cout << "ID: " << p2.id << " | Name: " << p2.name << " | Price: " << p2.price << "\n";

    return 0;
}