#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout << name << " " << age;
    }
};

class Student : public Person
{
    float avescore, score;
    float sumscore;

public:
    Student(string name, int age, float avescore, float score) : Person(name, age), avescore(avescore), score(score) {}
    float getSum()
    {
        sumscore = 0.4 * avescore + 0.6 * score;
        return sumscore;
    }
    void display()
    {
        Person::display();
        cout << " " << fixed << setprecision(2) << sumscore << endl;
    }
};

class Teacher : public Person
{
    vector<Student> select;
    int num;
    float avescore;

public:
    Teacher(string name, int age) : Person(name, age), num(0), avescore(0) {}
    void addStu(Student stu)
    {
        stu.getSum();
        select.push_back(stu);
        num++;
    }
    float getAvg()
    {
        for (auto i : select)
        {
            avescore += i.getSum();
        }
        avescore /= num;
        return avescore;
    }
    void display()
    {
        Person::display();
        cout << " " << num << " " << fixed << setprecision(2) << getAvg() << endl;
    }
    vector<Student> getSelect()
    {
        return select;
    }
};

void QAQ()
{
    string name;
    int age;
    cin >> name >> age;
    Teacher t(name, age);
    int n;
    cin >> n;
    while (n--)
    {
        string name;
        int age;
        float avescore, score;
        cin >> name >> age >> avescore >> score;
        Student stu(name, age, avescore, score);
        t.addStu(stu);
    }
    t.display();
    for (auto i : t.getSelect())
    {
        i.display();
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}