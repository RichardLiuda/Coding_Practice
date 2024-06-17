//头文件和日期类声明
#include <iostream>
#include <iomanip>
using namespace std;

class TDate
{
private:
    int year, month, day;

public:
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    void set(int y, int m, int d);
    void print();
    void addOneDay();
};

//----在以下区域完成部分成员函数的类外定义----
/********** Write your code here! **********/
void TDate::set(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
void TDate::print()
{
    cout.fill('0');
    cout << setw(4) << TDate::getYear() << setw(2) << TDate::getMonth() << setw(2) << TDate::getDay();
}
void TDate::addOneDay()
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (TDate::getYear() % 400 == 0 || (TDate::getYear() % 4 == 0 && TDate::getYear() % 100))
        days[2] = 29;
    if (TDate::getDay() < days[TDate::getMonth()])
        TDate::set(TDate::getYear(), TDate::getMonth(), TDate::getDay() + 1);
    else if (TDate::getMonth() == 12)
        TDate::set(TDate::getYear() + 1, 1, 1);
    else
        TDate::set(TDate::getYear(), TDate::getMonth() + 1, 1);
}
/*******************************************/
//主函数如下
int main()
{
    int t, y, m, d;
    cin >> t;
    while (t--)
    {
        TDate d1;
        cin >> y >> m >> d;
        d1.set(y, m, d);
        cout << "Today-";
        d1.print();
        d1.addOneDay();
        cout << " Tomorrow-";
        d1.print();
        cout << endl;
    }
    return 0;
}
