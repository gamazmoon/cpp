#include <iostream>
using namespace std;

int main()
{
    // تعریف یک ثابت: کلمه کلیدی const باعث می‌شود مقدار متغیر دیگر قابل تغییر نباشد
    const int NUMBER = 1;

    // NUMBER = 20; // خطا! شما نمی‌توانید مقدار یک ثابت را تغییر دهید

    cout << NUMBER;

    return 0;
}