#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CDate
{
private:
    int year, month, day;

public:
    CDate() {}
    CDate(int y, int m, int d) { year = y, month = m, day = d; }
    bool check()
    {
        int mon[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            mon[1] = 29;
        return (1 <= month && month <= 12 && 1 <= day && day <= mon[month - 1]);
    } // 检验日期是否合法
    bool isLeap();
    void print()
    {
        cout << year << "年" << month << "月" << day << "日"
             << " ";
    }
    char *GetDay()
    {
        char *p = new char[7];
        int cnt = 0;
        p[cnt++] = year / 1000 + '0';
        p[cnt++] = year % 1000 / 100 + '0';
        p[cnt++] = year % 100 / 10 + '0';
        p[cnt++] = year % 10 + '0';
        if (month < 10)
            p[cnt++] = '0';
        else
            p[cnt++] = month / 10 + '0'; // 要注意月份是从0开始的
        p[cnt++] = month % 10 + '0';
        if (day < 10)
            p[cnt++] = '0';
        else
            p[cnt++] = day / 10 + '0'; // 同上
        p[cnt++] = day % 10 + '0';
        p[cnt] = '\0';
        return p;
    }
};

// char *GetDay(char *p_id)
// {
//     char p[7];
//     int cnt = 0;
//     for (int i = 6; i < 13; i++)
//         p[cnt++] = p_id[i];
//     p[cnt] = '\0';
//     return p;
// }

class CStudentID
{
private:
    char *p_id, *p_name; // 身份证号码，姓名
    CDate birthday;      // 出生日期
    int registered;      // 登记否

public:
    CStudentID(char *p_idval, char *p_nameval, CDate &day) : birthday(day)
    {
        char *p;
        p_id = new char[19];
        p_name = new char[strlen(p_nameval)];
        strcpy(p_name, p_nameval);
        strcpy(p_id, p_idval);
        if (strlen(p_idval) == 15)
        {
            p = new char[7];
            strncpy(p, p_idval + 6, 6);
            p[6] = '\0';
        }
        else
        {
            p = new char[9];
            strncpy(p, p_idval + 6, 8);
            p[8] = '\0';
        }

        int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        int sum = 0;
        for (int i = 0; i < 17; i++)
        {
            sum += (p_idval[i] - '0') * a[i];
        }
        sum %= 11;
        char s[12] = "10X98765432";
        char ck = s[sum]; // 检验码

        // cout << "daycheck = " << day.check() << endl;
        // cout << "lenth = " << strlen(p_idval) << endl;
        // cout << "day.GetDay() = " << day.GetDay() << endl;
        // cout << "p = " << p << endl;
        // cout << "strcmp(p, day.GetDay()) = " << strcmp(p, day.GetDay()) << endl;
        // cout << "strcmp(p, day.GetDay() + 2) = " << strcmp(p, day.GetDay() + 2) << endl;

        // cout << !day.check() << " " << (strlen(p_idval) == 15 && strcmp(p, day.GetDay() + 2) != 0) << " " << (strlen(p_idval) == 18 && strcmp(p, day.GetDay()) != 0) << " " << (strlen(p_idval) != 15) << " " << (strlen(p_idval) != 18) << " " << (strlen(p_idval) == 18 && p_idval[17] != ck) << endl;
        bool flag = 0;
        for (int i = 0; p_idval[i] != '\0'; i++)
        {
            if (p_idval[i] < '0' || p_idval[i] > '9')
            {
                flag = 1;
                break;
            }
        }
        if (!day.check() || (strlen(p_idval) == 15 && strcmp(p, day.GetDay() + 2) != 0) || (strlen(p_idval) == 18 && strcmp(p, day.GetDay()) != 0) || (strlen(p_idval) != 15 && strlen(p_idval) != 18) || (strlen(p_idval) == 18 && p_idval[17] != ck) || flag)
        {
            registered = 0;
            cout << p_nameval << " illegal id" << endl;
        }
        else
        {
            registered = 1;
            cout << p_nameval << " ";
            day.print();
            cout << p_idval << endl;
        }
    } // 构造函数，若:日期非法;日期与id日期不符;id有非法字符;id不是15位或18位;id是18位但检验码不对,则输出"illegal id"并置registered=0。否则输出对象的属性并置registered=1.

    CStudentID(const CStudentID &r)
    {
        registered = r.registered;
        birthday = r.birthday;
        if (strlen(r.p_id) == 15)
        {
            p_id = new char[19];
            strcpy(p_id, r.p_id);
            for (int i = 14; i >= 6; i--)
            {
                p_id[i + 2] = p_id[i];
            }
            p_id[6] = birthday.GetDay()[0];
            p_id[7] = birthday.GetDay()[1];

            int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
            int sum = 0;
            for (int i = 0; i < 17; i++)
            {
                sum += (p_id[i] - '0') * a[i];
            }
            sum %= 11;
            char s[12] = "10X98765432";
            char ck = s[sum];
            // cout << "ck = " << ck << endl;

            p_id[17] = ck;
            p_id[18] = '\0';
        }
        else
        {
            p_id = new char[strlen(r.p_id)];
            strcpy(p_id, r.p_id);
        }
        p_name = new char[strlen(r.p_name)];
        strcpy(p_name, r.p_name);
        cout << p_name << " ";
        birthday.print();
        cout << p_id << endl;
    } // 拷贝构造函数，若r.p_id为15位则升到18位(加年份的19和校验位)

    bool checked() { return registered; }

    ~CStudentID()
    {
        delete p_id;
        delete p_name;
    }
};

void QAQ()
{
    int y, m, d;
    cin >> y >> m >> d;
    CDate day(y, m, d);
    char *id, *name;
    id = new char[19];
    name = new char[100];
    cin >> name >> id;
    CStudentID stu(id, name, day);
    if (stu.checked())
    {
        CStudentID stu1(stu);
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}