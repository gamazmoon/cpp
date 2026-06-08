// -----------------------------------------------------------------------------
// برنامه نمونه: سیستم ساده مدیریت سفارش
//
// هدف آموزشی:
//
// این برنامه نمونه‌ای آموزشی است که چند مبحث مهم برنامه‌نویسی را در یک
// برنامه واحد ترکیب می‌کند. دانشجو با خواندن و اجرای این برنامه با
// مفاهیم زیر آشنا می‌شود:
//
// 1) استفاده از struct برای تعریف موجودیت‌های مختلف
//    مانند:
//        Product   (کالا)
//        Customer  (مشتری)
//        Order     (سفارش)
//        Date      (تاریخ)
//
// 2) نگهداری مجموعه‌ای از داده‌ها با استفاده از آرایه
//
// 3) جست‌وجو در آرایه‌ها با استفاده از شناسه (id)
//
// 4) استفاده از تابع برای انجام عملیات مشخص
//    مانند:
//        جست‌وجوی کالا
//        جست‌وجوی مشتری
//        کاهش موجودی کالا
//        ثبت سفارش
//        نمایش اطلاعات
//
// 5) کاهش موجودی کالا هنگام ثبت سفارش
//
// 6) استفاده از یک منوی ساده برای اجرای عملیات مختلف
//
// -----------------------------------------------------------------------------
// در این برنامه چند نوع داده اصلی داریم:
//
// Customer ---- مشتری سیستم
// Product  ---- کالاهای موجود در انبار
// Order    ---- سفارش ثبت شده توسط مشتری
//
// هر سفارش شامل موارد زیر است:
//      مشتری
//      کالا
//      تعداد
//      تاریخ
//
// یک مشتری می‌تواند چند سفارش داشته باشد.
// یک کالا می‌تواند در چند سفارش مختلف وجود داشته باشد.
//
// -----------------------------------------------------------------------------
// محدودیت برنامه:
//
// برای سادگی آموزشی:
//
// - از vector استفاده نشده است
// - از pointer استفاده نشده است
// - از آرایه‌های ثابت استفاده شده است
//
// -----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_ITEMS = 100;

// -----------------------------------------------------------------------------

struct Product
{
    int id;
    string name;
    int stock;
    int price;
};

// -----------------------------------------------------------------------------

struct Customer
{
    int id;
    string name;
    string phone;
};

// -----------------------------------------------------------------------------

struct Date
{
    int year;
    int month;
    int day;
};

// -----------------------------------------------------------------------------

struct Order
{
    int customerId;
    int productId;
    int quantity;
    Date date;
};

// -----------------------------------------------------------------------------

int findProductIndexById(const Product items[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (items[i].id == id)
            return i;
    }

    return -1;
}

// -----------------------------------------------------------------------------

int findCustomerIndexById(const Customer customers[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (customers[i].id == id)
            return i;
    }

    return -1;
}

// -----------------------------------------------------------------------------

bool reduceStock(Product &p, int qty)
{
    if (qty <= 0)
        return false;

    if (p.stock >= qty)
    {
        p.stock -= qty;
        return true;
    }

    return false;
}

// -----------------------------------------------------------------------------

void showProducts(const Product items[], int count)
{
    cout << "\n=== Product List ===\n";

    cout << left
         << setw(8) << "ID"
         << setw(12) << "Name"
         << setw(8) << "Stock"
         << "Price\n";

    for (int i = 0; i < count; i++)
    {
        cout << left
             << setw(8) << items[i].id
             << setw(12) << items[i].name
             << setw(8) << items[i].stock
             << items[i].price
             << "\n";
    }
}

// -----------------------------------------------------------------------------

void showCustomers(const Customer customers[], int count)
{
    cout << "\n=== Customer List ===\n";

    cout << left
         << setw(8) << "ID"
         << setw(12) << "Name"
         << "Phone\n";

    for (int i = 0; i < count; i++)
    {
        cout << left
             << setw(8) << customers[i].id
             << setw(12) << customers[i].name
             << customers[i].phone
             << "\n";
    }
}

// -----------------------------------------------------------------------------

void showOrders(const Order orders[],
                int orderCount,
                const Customer customers[],
                int customerCount)
{
    cout << "\n=== Orders ===\n";

    cout << left
         << setw(12) << "Customer"
         << setw(10) << "Product"
         << setw(8) << "Qty"
         << "Date\n";

    for (int i = 0; i < orderCount; i++)
    {
        int c = findCustomerIndexById(customers,
                                      customerCount,
                                      orders[i].customerId);

        string cname = "Unknown";

        if (c != -1)
            cname = customers[c].name;

        cout << left
             << setw(12) << cname
             << setw(10) << orders[i].productId
             << setw(8) << orders[i].quantity
             << orders[i].date.year << "/"
             << orders[i].date.month << "/"
             << orders[i].date.day
             << "\n";
    }
}

// -----------------------------------------------------------------------------

void addCustomer(Customer customers[], int &count)
{
    if (count >= MAX_ITEMS)
    {
        cout << "Customer list is full.\n";
        return;
    }

    Customer c;

    cout << "Customer id: ";
    cin >> c.id;

    cout << "Customer name: ";
    cin >> c.name;

    cout << "Phone: ";
    cin >> c.phone;

    customers[count] = c;
    count++;
}

// -----------------------------------------------------------------------------

void addProduct(Product items[], int &count)
{
    if (count >= MAX_ITEMS)
    {
        cout << "Product list is full.\n";
        return;
    }

    Product p;

    cout << "Product id: ";
    cin >> p.id;

    cout << "Product name: ";
    cin >> p.name;

    cout << "Stock: ";
    cin >> p.stock;

    cout << "Price: ";
    cin >> p.price;

    items[count] = p;
    count++;
}

// -----------------------------------------------------------------------------

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

    cout << "Customer id: ";
    cin >> o.customerId;

    cout << "Product id: ";
    cin >> o.productId;

    cout << "Quantity: ";
    cin >> o.quantity;

    cout << "Date (yyyy mm dd): ";
    cin >> o.date.year >> o.date.month >> o.date.day;

    int cIdx = findCustomerIndexById(customers, customerCount, o.customerId);

    if (cIdx == -1)
    {
        cout << "Customer not found.\n";
        return;
    }

    int pIdx = findProductIndexById(items, productCount, o.productId);

    if (pIdx == -1)
    {
        cout << "Product not found.\n";
        return;
    }

    if (!reduceStock(items[pIdx], o.quantity))
    {
        cout << "Not enough stock.\n";
        return;
    }

    orders[orderCount] = o;
    orderCount++;

    cout << "Order registered successfully.\n";
}

// -----------------------------------------------------------------------------

int main()
{
    Product products[MAX_ITEMS] =
    {
        {101,"Rice",30,120},
        {102,"Oil",20,250},
        {103,"Sugar",25,110}
    };

    int productCount = 3;

    Customer customers[MAX_ITEMS] =
    {
        {1,"Ali","09120000001"},
        {2,"Sara","09120000002"}
    };

    int customerCount = 2;

    Order orders[MAX_ITEMS];
    int orderCount = 0;

    int choice;

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
                addProduct(products, productCount);
                break;

            case 4:
                addCustomer(customers, customerCount);
                break;

            case 5:
                registerOrder(products,
                              productCount,
                              customers,
                              customerCount,
                              orders,
                              orderCount);
                break;

            case 6:
                showOrders(orders,
                           orderCount,
                           customers,
                           customerCount);
                break;
        }

    } while (choice != 0);

    return 0;
}