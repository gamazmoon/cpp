#include <iostream>
using namespace std;

int main()
{
    double x, sum;

    cout << "Please enter x:";
    cin >> x;

    sum = 0;
    while (x != 0)
    {
        sum += x;

        cout << "Please enter x:";
        cin >> x;
    }

    return 0;
}

// int main(){
//     int i=1;

//     while(i<=5){
//         cout<<i<<",";

//         i++;//i=i+1 or i+=1
//     }

//     return 0;
// }

/*
int main()
{
    int x, y, z;

    cin >> x;
    cin >> y;

    //filter
    while(y==0){
        cout<<"Division by zero\n";
        cout<<"please enter your number again:";
        cin>>y;
    }

    z = x / y;
    return 0;
}
*/
/*
int main()
{
    double x = -5;
    double y=x;

    if(x<0){
        y=-x;
    }
    // else{}

    cout << y;

    return 0;
}
*/
/*
int main()
{
    double x = -5;
    double y;

    if (x < 0)
    {
        y = -x;
    }
    else
    {
        y = x;
    }

    cout << y;

    return 0;
}
*/

// int main()
// {
//     double score,x;
//     cout << "Please enter the score: ";
//     cin >> score>>x;

//     bool isInvalid=score < 0 || 20 < score;
//     if (isInvalid) // invalid
//     {
//         cout << "The score is invalid";
//         return 0;
//     }

//     if (0 <= score && score < 10)
//     {
//         cout << "D";
//     }

//     if (10 <= score && score < 14)
//     {
//         cout << "C";
//     }

//     if (14 <= score && score < 17)
//     {
//         cout << "B";
//     }

//     if (17 <= score && score <= 20)
//     {
//         cout << "A";
//     }

//     return 0;
// }

// int main()
// {
//     double score;
//     cout << "Please enter the score: ";
//     cin >> score;

//     if (score < 0 || 20 < score)
//     { // invalid
//         cout << "The score is invalid";
//     }
//     else
//     {
//         if (score < 10)
//         { // it means 0<=score<10
//             cout << "D";
//         }
//         else
//         { // it means 10<=score<=20
//             if (score < 14)
//             { // it means 10<=score<14
//                 cout << "C";
//             }
//             else
//             { // it means 14<=score<=20
//                 if (score < 17)
//                 { // it means 14<=score<17
//                     cout << "B";
//                 }
//                 else
//                 { // it means 17<=score<=20
//                     cout << "A";
//                 }
//             }
//         }
//     }

//     return 0;
// }

// int main()
// {
//     double t = 0;
//     cin >> t;

//     if (t < 2)
//     {
//         cout << "cold";
//     }
//     else
//     {
//         if (t < 25)
//         {
//             cout << "normal";
//         }
//         else
//         {
//             cout << "hot";
//         }
//     }

//     return 0;
// }

// int main()
// {
//     int x;
//     cin>>x;

//     cout<<x+10;

//     return 0;
// }

// cout << 11 + 2 << "\t";
// cout << 11 - 2 << "\t";
// cout << 11 * 2 << "\t";
// cout << 11 / 2 << "\t";

// cout << 11.0 + 2.0 << "\t";
// cout << 11.0 - 2.0 << "\t";
// cout << 11.0 * 2.0 << "\t";
// cout << 11.0 / 2.0 << "\t";

//   cout << 11 / 2;
//     cout << "\n 1----------- \n";
//     cout << 11.0 / 2.0;

//     cout << "\n 2----------- \n";
//     cout << 11 / 2.0;