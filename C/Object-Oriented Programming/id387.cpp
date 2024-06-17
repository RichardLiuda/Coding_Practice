#include <iostream>
#include <string>
using namespace std;

class Lesson
{
private:
    string id;
    double score;
    double credit;

public:
    Lesson() {}
    Lesson(string i, double c, double s)
    {
        id = i;
        score = s;
        credit = c;
    }
    double getScore()
    {
        return score;
    }
    double getCredit()
    {
        return credit;
    }
};

class Student
{
private:
    string id;
    string name;
    int type;
    int lesson_num;
    double total_credit;
    Lesson *les;

public:
    Student(string i, string n, int t);
    Student(const Student &stu);
    ~Student()
    {
        delete[] les;
    }
    void record();
    void count();
    void display(char op);
};
// 以下填空完成类Student的5个成员函数定义（析构函数已经定义，无需再写）
// 注意，类成员函数在类外实现，函数首部要带....
/********** Write your code here! **********/
Student::Student(string i, string n, int t) : id(i), name(n), type(t)
{
    lesson_num = 0;
    total_credit = 0;
}
void Student::record()
{
    int n;
    cin >> n;
    lesson_num = n;
    les = new Lesson[n];
    for (int i = 0; i < n; i++)
    {
        string id;
        double c, s;
        cin >> id >> c >> s;
        Lesson tmp(id, c, s);
        les[i] = tmp;
    }
}
void Student::count()
{
    for (int i = 0; i < lesson_num; i++)
    {
        if (les[i].getScore() >= 60)
        {
            total_credit += les[i].getCredit();
        }
    }
}
Student::Student(const Student &rhs)
{
    id = "2023";
    id.append(rhs.id);
    name = rhs.name;
    type = 1;
    // cout << lesson_num << endl;
    lesson_num = 0;
    total_credit = 0;
    les = new Lesson[rhs.lesson_num];
    for (int i = 0; i < rhs.lesson_num; i++)
    {
        if (rhs.les[i].getScore() >= 60)
        {
            les[lesson_num] = rhs.les[i];
            // cout << lesson_num << " " << i << endl;
            // les[lesson_num] = rhs.les[i];
            lesson_num++;
        }
    }
    // cout << endl;
    // cout << id << " " << name << " " << (!type ? "undergraduate " : "postgraduate ") << lesson_num << " " << total_credit << endl;
}
void Student::display(char op)
{
    if (op == 'C')
    {
        cout << id << " " << name << " " << (!type ? "undergraduate " : "postgraduate ") << lesson_num << " " << total_credit << endl;
    }
    else
    {
        cout << id << " " << name << " " << (!type ? "undergraduate" : "postgraduate") << endl;
    }
}
/*******************************************/
// 主函数
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    string id, name;
    char op1, op2;
    cin >> t;
    while (t--)
    {
        cin >> id >> name;
        Student under_stu = Student(id, name, 0);
        under_stu.record();
        under_stu.count();
        Student post_stu = Student(under_stu);
        post_stu.count();

        cin >> op1 >> op2;
        under_stu.display(op1);
        post_stu.display(op2);
    }
    return 0;
}
