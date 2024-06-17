#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Student
{
protected:
    string name;        // 学生姓名
    int type;           // 学生类别:1表示本科生，2表示研究生
    int courses[3];     // 3门课的成绩
    string courseGrade; // 成绩等级
public:
    Student(string n, string t, int a1, int a2, int a3) : name(n), type(t == "1" ? 1 : 2)
    {
        courses[0] = a1;
        courses[1] = a2;
        courses[2] = a3;
    } // 构造方法
    virtual void calculateGrade() = 0; // 计算成绩等级
    void print()
    {
        cout << name << "," << (type == 1 ? "本科生" : "研究生") << "," << courseGrade << endl;
    } // 输出信息
};

class Undergraduate : public Student
{
public:
    Undergraduate(string n, int a1, int a2, int a3) : Student(n, "1", a1, a2, a3) {}
    void calculateGrade()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += courses[i];
        }
        sum /= 3;
        if (sum >= 80)
        {
            courseGrade = "优秀";
        }
        else if (sum >= 70)
        {
            courseGrade = "良好";
        }
        else if (sum >= 60)
        {
            courseGrade = "一般";
        }
        else if (sum >= 50)
        {
            courseGrade = "及格";
        }
        else
            courseGrade = "不及格";
    }
};

class Postgraduate : public Student
{
public:
    Postgraduate(string n, int a1, int a2, int a3) : Student(n, "2", a1, a2, a3) {}
    void calculateGrade()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += courses[i];
        }
        sum /= 3;
        if (sum >= 90)
        {
            courseGrade = "优秀";
        }
        else if (sum >= 80)
        {
            courseGrade = "良好";
        }
        else if (sum >= 70)
        {
            courseGrade = "一般";
        }
        else if (sum >= 60)
        {
            courseGrade = "及格";
        }
        else
            courseGrade = "不及格";
    }
};

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
    // Undergraduate u;
    // Postgraduate p;
    Student *stu[t];
    for (int i = 0; i < t; i++)
    {
        string n, t;
        int a1, a2, a3;
        cin >> n >> t >> a1 >> a2 >> a3;
        if (t == "1")
        {
            stu[i] = new Undergraduate(n, a1, a2, a3);
            stu[i]->calculateGrade();
            stu[i]->print();
        }
        else if (t == "2")
        {
            stu[i] = new Postgraduate(n, a1, a2, a3);
            stu[i]->calculateGrade();
            stu[i]->print();
        }
    }
    return 0;
}