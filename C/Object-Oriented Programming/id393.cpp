// 补充头文件和CDate类定义
/********** Write your code here! **********/
#include <bits/stdc++.h>
using namespace std;

class CDate
{
    int year, month, day;

public:
    CDate(int date = 0)
    {
        year = date / 10000;
        month = (date % 10000) / 100;
        day = date % 100;
    }
    operator int()
    {
        return year * 10000 + month * 100 + day;
    }
    void Print()
    {
        cout.fill('0');
        cout << setw(4) << year << "年" << setw(2) << month << "月" << setw(2) << day << "日" << endl;
    }
};
/*******************************************/
// 主函数
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t, t1, t2;
    CDate C1, C2;
    cin >> t;
    while (t--)
    {
        cin >> t1 >> t2;
        C1 = t1;
        C2 = t2;
        ((C1 > C2) ? C1 : C2).Print(); // 日期大的输出，在代码C1>C2中，会自动把C1和C2转换为整数进行比较
    }
    return 0;
}