// -----------------------------------------------------------------------------
// برنامه نمونه: سیستم مدیریت سفارش (نسخه نهایی و مهندسی‌شده با رعایت اصل SoC)
//
// هدف آموزشی:
// این پروژه الگو و ساختار یک کد استاندارد و تمیز (Clean Code) را با ترکیب مفاهیم زیر به دانشجو یاد می‌دهد:
//
// 1) اصل تفکیک وظایف (Separation of Concerns): جداسازی کامل لایه دریافت ورودی (UI)
//    از لایه منطق کلان برنامه (Business Logic).
// 2) متدهای داخلی (Member Functions): هر شیء با داشتن متد readFromConsole خودش مسئول
//    دریافت و پر کردن داده‌های خودش است و فضای تابع main یا لایه پردازش را شلوغ نمی‌کند.
// 3) توابع عمومی: مدیریت هماهنگی، اعتبارسنجی و تعاملات کلان بین آرایه‌های مختلف ساختارها.
//
// -----------------------------------------------------------------------------
// معماری داده‌ها و توابع برنامه:
//
// ساختارهای داده (Structs):
//   - Date     ----> دارای متد print() برای نمایش و readFromConsole() برای دریافت تاریخ
//   - Product  ----> دارای متد reduceStock() برای کسر موجودی و readFromConsole() برای دریافت کالا
//   - Customer ----> دارای متد readFromConsole() برای دریافت اطلاعات مشتری
//   - Order    ----> دارای متد readFromConsole() برای دریافت اطلاعات سفارش (ترکیب با متد Date)
//
// توابع عمومی (لایه منطق و پردازش آرایه‌ها):
//   - addProduct()   / addCustomer()   ----> دریافت شیء کاملاً پر شده و افزودن به آرایه مرجع
//   - registerOrder()                  ----> دریافت سفارش آماده، اعتبارسنجی اصالت و کسر موجودی انبار
//   - findProductIndexById() / findCustomerIndexById() ----> جست‌وجو و اعتبارسنجی فیلدها
//   - showProducts() / showCustomers() / showOrders()  ----> نمایش لیست‌های خروجی
//
// -----------------------------------------------------------------------------
// محدودیت برنامه (جهت حفظ سادگی آموزشی):
// - از vector و pointer استفاده نشده است تا تمرکز کاملاً روی Struct، Method و معماری SoC باشد.
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// حداکثر ظرفیت آرایه‌ها برای سادگی کار
const int MAX_ITEMS = 100;

// =============================================================================
// بخش اول: تعریف ساختارها (Structs) به همراه متدهای داخلی هرکدام
// =============================================================================

// ۱) ساختار تاریخ (Date) - دارای متد داخلی برای چاپ و دریافت
struct Date
{
    int year;
    int month;
    int day;

    // متد داخلی برای چاپ تاریخ
    void print() const
    {
        cout << year << "/" << month << "/" << day;
    }

    // متد داخلی برای دریافت تاریخ از کیبورد
    void readFromConsole()
    {
        cin >> year >> month >> day;
    }
};

// -----------------------------------------------------------------------------
// ۲) ساختار کالا (Product) - دارای متد داخلی برای مدیریت موجودی و دریافت ورودی
struct Product
{
    int id;
    string name;
    int stock;
    int price;

    // متد دریافت اطلاعات کالا از کاربر (تفکیک لایه ورودی - UI)
    void readFromConsole()
    {
        cout << "Product id: ";
        cin >> id;
        cout << "Product name: ";
        cin >> name;
        cout << "Stock: ";
        cin >> stock;
        cout << "Price: ";
        cin >> price;
    }

    // متد بررسی و کاهش موجودی کالا (منطق داخلی کلا)
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

        stock = stock - qty;
        return true;
    }
};

// -----------------------------------------------------------------------------
// ۳) ساختار مشتری (Customer) - دارای متد داخلی دریافت اطلاعات
struct Customer
{
    int id;
    string name;
    string phone;

    // متد دریافت اطلاعات مشتری از کاربر
    void readFromConsole()
    {
        cout << "Customer id: ";
        cin >> id;
        cout << "Customer name: ";
        cin >> name;
        cout << "Phone: ";
        cin >> phone;
    }
};

// -----------------------------------------------------------------------------
// ۴) ساختار سفارش (Order) - نمونه‌ای از ترکیب ساختارها (Nested Struct)
struct Order
{
    int customerId;
    int productId;
    int quantity;
    Date date; // ساختار Date به عنوان یک عضو درون ساختار Order استفاده شده است

    // متد دریافت اطلاعات سفارش از کاربر
    void readFromConsole()
    {
        cout << "Customer id: ";
        cin >> customerId;
        cout << "Product id: ";
        cin >> productId;
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Date (yyyy mm dd): ";
        date.readFromConsole(); // فراخوانی متد داخلی ساختار تاریخ برای پر کردن فیلد date
    }
};

// =============================================================================
// بخش دوم: توابع عمومی (لایه منطق برنامه و مدیریت کلان آرایه‌ها)
// =============================================================================

// جست‌وجوی کالا بر اساس ID و برگرداندن اندیس آن
int findProductIndexById(const Product items[], int count, int id)
{
    for (int i = 0; i < count; i = i + 1)
    {
        if (items[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

// -----------------------------------------------------------------------------
// جست‌وجوی مشتری بر اساس ID و برگرداندن اندیس آن
int findCustomerIndexById(const Customer customers[], int count, int id)
{
    for (int i = 0; i < count; i = i + 1)
    {
        if (customers[i].id == id)
        {
            return i;
        }
    }
    
    return -1;
}

// -----------------------------------------------------------------------------
// نمایش لیست کالاها با گرفتن آرایه‌ای از ساختار Product
void showProducts(const Product items[], int count)
{
    cout << "\n=== Product List ===\n";
    cout << left << setw(8) << "ID" << setw(12) << "Name" << setw(8) << "Stock" << "Price\n";

    for (int i = 0; i < count; i = i + 1)
    {
        cout << left << setw(8) << items[i].id << setw(12) << items[i].name
             << setw(8) << items[i].stock << items[i].price << "\n";
    }
}

// -----------------------------------------------------------------------------
// نمایش لیست مشتریان با گرفتن آرایه‌ای از ساختار Customer
void showCustomers(const Customer customers[], int count)
{
    cout << "\n=== Customer List ===\n";
    cout << left << setw(8) << "ID" << setw(12) << "Name" << "Phone\n";

    for (int i = 0; i < count; i = i + 1)
    {
        cout << left << setw(8) << customers[i].id << setw(12) << customers[i].name
             << customers[i].phone << "\n";
    }
}

// -----------------------------------------------------------------------------
// نمایش سفارشات ثبت شده
void showOrders(const Order orders[], int orderCount, const Customer customers[], int customerCount)
{
    cout << "\n=== Orders ===\n";
    cout << left << setw(12) << "Customer" << setw(10) << "Product" << setw(8) << "Qty" << "Date\n";

    for (int i = 0; i < orderCount; i = i + 1)
    {
        int c = findCustomerIndexById(customers, customerCount, orders[i].customerId);
        string cname = "Unknown";
        if (c != -1)
        {
            cname = customers[c].name;
        }

        cout << left << setw(12) << cname << setw(10) << orders[i].productId << setw(8) << orders[i].quantity;
        orders[i].date.print(); // فراخوانی متد داخلی ساختار تاریخ
        cout << "\n";
    }
}

// -----------------------------------------------------------------------------
// اضافه کردن کالا: فقط یک شیءِ معتبر و پر شده را گرفته و به آرایه اضافه می‌کند
void addProduct(Product items[], int &count, const Product &p)
{
    if (count >= MAX_ITEMS)
    {
        cout << "Product list is full.\n";
        return;
    }

    items[count] = p; // کپی شیء آماده در آرایه
    count++;
    cout << "Product added successfully.\n";
}

// -----------------------------------------------------------------------------
// اضافه کردن مشتری: دریافت شیءِ پر شده و اضافه کردن آن به آرایه مشتریان
void addCustomer(Customer customers[], int &count, const Customer &c)
{
    if (count >= MAX_ITEMS)
    {
        cout << "Customer list is full.\n";
        return;
    }

    customers[count] = c;
    count++;
    cout << "Customer added successfully.\n";
}

// -----------------------------------------------------------------------------
// ثبت یک سفارش جدید
// این تابع هیچ ورودی مستقیم یا cin از کاربر ندارد، فقط صحتِ سفارش را بررسی می‌کند.
bool registerOrder(Product items[], int productCount,
                   Customer customers[], int customerCount,
                   Order orders[], int &orderCount,
                   const Order &newOrder)
{
    if (orderCount >= MAX_ITEMS)
    {
        cout << "Order list is full.\n";
        return false;
    }

    // ۱. بررسی اصالت مشتری (اعتبارسنجی لایه بیزینس)
    int cIdx = findCustomerIndexById(customers, customerCount, newOrder.customerId);
    if (cIdx == -1)
    {
        cout << "Customer not found.\n";
        return false;
    }

    // ۲. بررسی اصالت کالا
    int pIdx = findProductIndexById(items, productCount, newOrder.productId);
    if (pIdx == -1)
    {
        cout << "Product not found.\n";
        return false;
    }

    // ۳. فراخوانی متد کالا برای کاهش موجودی انبار
    if (!items[pIdx].reduceStock(newOrder.quantity))
    {
        cout << "Not enough stock.\n";
        return false;
    }

    // ۴. ثبت سفارش در صورت عبور از تمام فیلترها
    orders[orderCount] = newOrder;
    orderCount++;
    return true;
}

// =============================================================================
// بخش سوم: تابع اصلی (کنترل‌کننده جریان منو و برنامه)
// =============================================================================
int main()
{
    // هاردکد کردن داده‌های اولیه پیش‌فرض سیستم برای راحتی تست تست برنامه
    Product products[MAX_ITEMS] = {{101, "Rice", 30, 120}, {102, "Oil", 20, 250}, {103, "Sugar", 25, 110}};
    int productCount = 3;

    Customer customers[MAX_ITEMS] = {{1, "Ali", "09120000001"}, {2, "Sara", "09120000002"}};
    int customerCount = 2;

    Order orders[MAX_ITEMS];
    int orderCount = 0;

    int choice;

    // منوی اصلی برنامه (تابع main فقط جریان را کنترل می‌کند و درگیر جزییات cin نیست)
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
        case 1:
            showProducts(products, productCount);
            break;
        case 2:
            showCustomers(customers, customerCount);
            break;
        case 3:
        {
            Product p;
            p.readFromConsole();                   // لایه ورود اطلاعات (UI) کاملاً کپسوله و مستقل
            addProduct(products, productCount, p); // لایه پردازش و ذخیره داده
            break;
        }
        case 4:
        {
            Customer c;
            c.readFromConsole(); // هر شیء خودش داده‌هایش را دریافت میکند
            addCustomer(customers, customerCount, c);
            break;
        }
        case 5:
        {
            Order o;
            o.readFromConsole(); // ساخت شیءِ سفارش مستقل از منطقِ ثبت آن
            if (registerOrder(products, productCount, customers, customerCount, orders, orderCount, o))
            {
                cout << "Order registered successfully.\n";
            }
            break;
        }
        case 6:
            showOrders(orders, orderCount, customers, customerCount);
            break;
        }
    } while (choice != 0);

    return 0;
}