// -----------------------------------------------------------------------------
// مثال: ساختارهای تو در تو (Nested Structs)
//
// هدف آموزشی:
// - یادگیری تعریف یک Struct در داخل Struct دیگر
// - آشنایی با مدل‌سازی روابط بین موجودیت‌ها (ارتباط سفارش، مشتری و کالا)
// - دسترسی به اعضای ساختار تو در تو با دو بار عملگر نقطه (o.date.year)
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// ساختار تاریخ
struct Date
{
    int year;
    int month;
    int day;
};

// ساختار سفارش
struct Order
{
    int customerId; // شناسه مشتری 
    int productId;  // شناسه کالا
    int quantity;   // تعداد سفارش
    Date date;      // تاریخ سفارش
};

int main()
{
    Order o;

    // مقداردهی به اطلاعات اصلی سفارش با آیدی‌ها
    o.customerId = 1; // شناسه مشتری. برای مثال شناسه علی
    o.productId = 101;   // شناسه کالا. برای مثال شناسه برنج
    o.quantity = 2;

    // مقداردهی به فیلدهای ساختار تو در تو
    o.date.year = 2026;
    o.date.month = 6;
    o.date.day = 10;

    // نمایش اطلاعات سفارش
    cout << "--- Order Details ---\n";
    cout << "Customer ID: " << o.customerId << "\n";
    cout << "Product ID: "  << o.productId << "\n";
    cout << "Quantity: "    << o.quantity << "\n";

    // نمایش تاریخ سفارش از دل ساختار تو در تو
    cout << "Order Date: "  << o.date.year << "/"
         << o.date.month << "/"
         << o.date.day << "\n";

    return 0;
}