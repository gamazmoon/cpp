// -----------------------------------------------------------------------------
// برنامه نمونه: سیستم ساده مدیریت سفارش (نسخه توسعه‌یافته با متدهای داخلی)
//
// هدف آموزشی:
//
// این برنامه نمونه‌ای آموزشی است که مفاهیم کلیدی ساختارها را در یک پروژه واحد
// ترکیب می‌کند. دانشجو با مطالعه این کد، تفاوت و کاربرد همزمان دو رویکرد زیر را می‌آموزد:
//
// 1) متدهای داخلی (Member Functions): تعریف تابع درون struct برای عملیاتی که
//    مستقیماً با داده‌های خودِ آن ساختار سر و کار دارند (مانند کاهش موجودی کالا).
//
// 2) توابع عمومی (ارسال ساختار به تابع): تعریف تابع خارج از struct برای مدیریت
//    تعاملات بین چند ساختار مختلف و آرایه‌ها (مانند ثبت سفارش یا جست‌وجو).
//
// مفاهیم کلیدی که دانشجو در این پروژه یاد می‌گیرد:
//
// 1) استفاده از struct برای تعریف موجودیت‌ها (Product, Customer, Order, Date)
// 2) تعریف و فراخوانی متدها درون یک struct
// 3) مفهوم ترکیب ساختارها یا ساختارهای تودرتو (Nested Structs - استفاده از Date در Order)
// 4) نگهداری مجموعه‌ای از ساختارها با استفاده از آرایه‌های ثابت
// 5) جست‌وجو در آرایه‌ای از ساختارها با استفاده از شناسه (id)
// 6) کپسوله‌سازی منطق کاهش موجودی کالا (reduceStock) درون خودِ ساختار کالا
// 7) استفاده از یک منوی تعاملی ساده برای اجرای عملیات مختلف
//
// -----------------------------------------------------------------------------
// معماری داده‌ها و توابع برنامه:
//
// ساختارهای داده (Structs):
//   - Date     ----> دارای متد داخلی print() برای نمایش تاریخ
//   - Product  ----> دارای متد داخلی reduceStock() برای بررسی و کسر موجودی انبار
//   - Customer ----> ساختار ساده برای ذخیره اطلاعات مشتری
//   - Order    ----> ترکیب شناسه مشتری، کالا و ساختار Date
//
// توابع عمومی (ارسال آرایه ساختارها):
//   - showProducts()       / showCustomers()       ----> نمایش لیست‌ها
//   - findProductIndexById() / findCustomerIndexById() ----> جست‌وجو در آرایه‌ها
//   - addProduct()         / addCustomer()         ----> افزودن با پاس دادن مرجع (Reference)
//   - registerOrder()                              ----> ترکیب آرایه‌ها و فراخوانی متد کالا
//   - showOrders()                                 ----> نمایش سفارشات و فراخوانی متد تاریخ
//
// -----------------------------------------------------------------------------
// محدودیت برنامه (جهت حفظ سادگی آموزشی):
//
// - از vector استفاده نشده است.
// - از pointer استفاده نشده است.
// - از آرایه‌های ثابت استفاده شده است تا تمرکز کاملاً روی Struct و Method باشد.
//
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// حداکثر ظرفیت آرایه‌ها برای سادگی کار و عدم استفاده از Vector
const int MAX_ITEMS = 100;

// -----------------------------------------------------------------------------
// ۱) ساختار تاریخ (Date) - دارای متد داخلی
// -----------------------------------------------------------------------------
struct Date
{
    int year;
    int month;
    int day;

    // *** این یک «متد» یا تابع عضو (Member Function) است ***
    // چون این تابع درون خود ساختار تعریف شده، به طور مستقیم به متغیرهای year، month و day
    // همان شیء دسترسی دارد و نیازی نیست ساختار را به عنوان ورودی به آن پاس بدهیم.
    void print() const 
    {
        cout << year << "/" << month << "/" << day;
    }
};

// -----------------------------------------------------------------------------
// ۲) ساختار کالا (Product) - دارای متد داخلی برای مدیریت موجودی
// -----------------------------------------------------------------------------
struct Product
{
    int id;
    string name;
    int stock;
    int price;

    // *** این یک «متد» است ***
    // وظیفه این متد، بررسی و کاهش موجودی همین کالای خاص است.
    // به نحوه استفاده از کلمه کلیدی یا دسترسی مستقیم به stock دقت کنید.
    bool reduceStock(int qty)
    {
        if (qty <= 0) return false;

        // اگر موجودی انبار انبار از تعداد درخواستی بیشتر یا مساوی بود
        if (stock >= qty)
        {
            stock -= qty; // موجودی همین کالا کم می‌شود
            return true;  // عملیات موفقیت‌آمیز بود
        }
        return false;     // موجودی کافی نیست
    }
};

// -----------------------------------------------------------------------------
// ۳) ساختار مشتری (Customer) - یک ساختار ساده بدون متد
// -----------------------------------------------------------------------------
struct Customer
{
    int id;
    string name;
    string phone;
};

// -----------------------------------------------------------------------------
// ۴) ساختار سفارش (Order) - نمونه‌ای از ترکیب ساختارها (Nested Struct)
// -----------------------------------------------------------------------------
struct Order
{
    int customerId;
    int productId;
    int quantity;
    Date date; // ساختار Date به عنوان یک عضو درون ساختار Order استفاده شده است
};

// =============================================================================
// توابع عمومی (توابع خارج از ساختار)
// این توابع نمونه بارز «ارسال ساختار یا آرایه‌ای از ساختارها به تابع» هستند.
// =============================================================================

// این تابع آرایه‌ای از کالاها را می‌گیرد و بر اساس ID، اندیس آن کالا را پیدا می‌کند
int findProductIndexById(const Product items[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (items[i].id == id)
            return i; // اندیس کالا پیدا شد
    }
    return -1; // کالا یافت نشد
}

// -----------------------------------------------------------------------------
// این تابع آرایه‌ای از مشتریان را می‌گیرد و بر اساس ID، اندیس مشتری را پیدا می‌کند
int findCustomerIndexById(const Customer customers[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (customers[i].id == id)
            return i; // اندیس مشتری پیدا شد
    }
    return -1; // مشتری یافت نشد
}

// -----------------------------------------------------------------------------
// نمایش لیست کالاها با گرفتن آرایه‌ای از ساختار Product
void showProducts(const Product items[], int count)
{
    cout << "\n=== Product List ===\n";
    cout << left << setw(8) << "ID" << setw(12) << "Name" << setw(8) << "Stock" << "Price\n";

    for (int i = 0; i < count; i++)
    {
        // دسترسی به اعضای هر ساختار با استفاده از اپراتور نقطه (.)
        cout << left
             << setw(8)  << items[i].id
             << setw(12) << items[i].name
             << setw(8)  << items[i].stock
             << items[i].price << endl;
    }
}

// -----------------------------------------------------------------------------
// نمایش لیست مشتریان با گرفتن آرایه‌ای از ساختار Customer
void showCustomers(const Customer customers[], int count)
{
    cout << "\n=== Customer List ===\n";
    cout << left << setw(8) << "ID" << setw(12) << "Name" << "Phone\n";

    for (int i = 0; i < count; i++)
    {
        cout << left
             << setw(8)  << customers[i].id
             << setw(12) << customers[i].name
             << customers[i].phone << endl;
    }
}

// -----------------------------------------------------------------------------
// نمایش سفارشات ثبت شده
// این تابع آرایه‌های مختلفی از ساختارهای متفاوت را به عنوان ورودی دریافت می‌کند
void showOrders(const Order orders[], int orderCount, const Customer customers[], int customerCount)
{
    cout << "\n=== Orders ===\n";
    cout << left << setw(12) << "Customer" << setw(10) << "Product" << setw(8) << "Qty" << "Date\n";

    for (int i = 0; i < orderCount; i++)
    {
        // پیدا کردن نام مشتری بر اساس شناسه مشتری موجود در سفارش
        int c = findCustomerIndexById(customers, customerCount, orders[i].customerId);
        string cname = "Unknown";
        if (c != -1) cname = customers[c].name;

        cout << left
             << setw(12) << cname
             << setw(10) << orders[i].productId
             << setw(8)  << orders[i].quantity;
        
        // *** فراخوانی متد داخلی ساختار تاریخ ***
        // به جای فرمت‌دهی دستی، متد print کپسوله‌شده در ساختار Date را صدا می‌زنیم
        orders[i].date.print(); 
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// اضافه کردن کالا به آرایه (ارسال تعداد با ارجاع یا Reference جهت تغییر متغیر اصلی)
void addProduct(Product items[], int &count)
{
    if (count >= MAX_ITEMS)
    {
        cout << "Product list is full.\n";
        return;
    }

    Product p; // ایجاد یک متغیر موقت از نوع ساختار کالا
    cout << "Product id: ";   cin >> p.id;
    cout << "Product name: "; cin >> p.name;
    cout << "Stock: ";        cin >> p.stock;
    cout << "Price: ";        cin >> p.price;

    items[count] = p; // کپی کردن ساختار پر شده در آرایه اصلی
    count++;          // افزایش تعداد کالاهای موجود در سیستم
}

// -----------------------------------------------------------------------------
// اضافه کردن مشتری جدید به آرایه مشتریان
void addCustomer(Customer customers[], int &count)
{
    if (count >= MAX_ITEMS)
    {
        cout << "Customer list is full.\n";
        return;
    }

    Customer c;
    cout << "Customer id: ";   cin >> c.id;
    cout << "Customer name: "; cin >> c.name;
    cout << "Phone: ";         cin >> c.phone;

    customers[count] = c;
    count++;
}

// -----------------------------------------------------------------------------
// ثبت یک سفارش جدید و کسر موجودی انبار
void registerOrder(Product items[], int productCount,
                   Customer customers[], int customerCount,
                   Order orders[], int &orderCount)
{
    if (orderCount >= MAX_ITEMS)
    {
        cout << "Order list is full.\n";
        return;
    }

    Order o;
    cout << "Customer id: ";   cin >> o.customerId;
    cout << "Product id: ";    cin >> o.productId;
    cout << "Quantity: ";      cin >> o.quantity;
    cout << "Date (yyyy mm dd): "; cin >> o.date.year >> o.date.month >> o.date.day;

    // ۱. بررسی اصالت مشتری (آیا این مشتری اصلاً وجود دارد؟)
    int cIdx = findCustomerIndexById(customers, customerCount, o.customerId);
    if (cIdx == -1)
    {
        cout << "Customer not found.\n";
        return;
    }

    // ۲. بررسی اصالت کالا (آیا این کالا اصلاً در انبار هست؟)
    int pIdx = findProductIndexById(items, productCount, o.productId);
    if (pIdx == -1)
    {
        cout << "Product not found.\n";
        return;
    }

    // ۳. *** فراخوانی متد کالا برای کاهش موجودی انبار ***
    // به این نحوه‌ی نگارش دقت کنید؛ ما شیءِ کالا را به تابع خارجی نفرستادیم، 
    // بلکه به خودِ آن کالا (items[pIdx]) دستور دادیم که با متد داخلی‌اش، موجودی خود را کم کند.
    if (!items[pIdx].reduceStock(o.quantity))
    {
        cout << "Not enough stock.\n";
        return;
    }

    // ۴. ثبت نهایی سفارش در صورت موفقیت‌آمیز بودن مراحل قبل
    orders[orderCount] = o;
    orderCount++;

    cout << "Order registered successfully.\n";
}

// -----------------------------------------------------------------------------
int main()
{
    // مقداردهی اولیه به آرایه محصولات (هاردکد برای راحتی تست تست برنامه)
    Product products[MAX_ITEMS] =
    {
        {101,"Rice",30,120},
        {102,"Oil",20,250},
        {103,"Sugar",25,110}
    };
    int productCount = 3;

    // مقداردهی اولیه به آرایه مشتریان
    Customer customers[MAX_ITEMS] =
    {
        {1,"Ali","09120000001"},
        {2,"Sara","09120000002"}
    };
    int customerCount = 2;

    // ایجاد آرایه سفارشات (در ابتدا خالی است)
    Order orders[MAX_ITEMS];
    int orderCount = 0;

    int choice;

    // منوی اصلی برنامه برای تعامل کاربر
    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1 - Show products\n";
        cout << "2 - Show customers\n";
        cout << "3 - Add product\n";
        cout << "4 - Add customer\n";
        cout << "5 - Register order\n";
        cout << "6 - Show orders\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: showProducts(products, productCount); break;
            case 2: showCustomers(customers, customerCount); break;
            case 3: addProduct(products, productCount); break;
            case 4: addCustomer(customers, customerCount); break;
            case 5: registerOrder(products, productCount, customers, customerCount, orders, orderCount); break;
            case 6: showOrders(orders, orderCount, customers, customerCount); break;
        }
    } while (choice != 0);

    return 0;
}