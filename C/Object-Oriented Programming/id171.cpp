#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Student
{
private:
    int id;              // 学号
    int score;           // 成绩
    static int maxscore; // 最高分数
    static int maxid;    // 最高分数学生学号
public:
    Student(int ti = 0, int ts = 0) : id(ti), score(ts) {}
    static void findMax(Student &st); // 寻找最高成绩和学号
    static int getMaxScore();         // 返回最高成绩
    static int getMaxID();            // 返回最高成绩的学号
};

int Student::maxscore = 0;
int Student::maxid = 114514;

void Student::findMax(Student &st)
{
    if (st.score > maxscore)
    {
        maxscore = st.score;
        maxid = st.id;
    }
}

int Student::getMaxScore()
{
    return maxscore;
}

int Student::getMaxID()
{
    return maxid;
}

void QAQ()
{
    int id, score;
    cin >> id >> score;
    Student st(id, score);
    Student::findMax(st);
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
    cout << Student::getMaxID() << "--" << Student::getMaxScore() << endl;
    return 0;
}