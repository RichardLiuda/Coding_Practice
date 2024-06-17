#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
typedef double db;
#define int long long

struct birth
{
    int y, m, d;
};

class StuInfo
{
private:
    int id;
    string name;
    birth birthday;
    float score;

public:
    int getId() { return id; }
    string getName() { return name; }
    birth getBirthday() { return birthday; }
    float getScore() { return score; }
    void set(int id, string name, birth birthday, float score)
    {
        this->id = id;
        this->name = name;
        this->birthday = birthday;
        this->score = score;
    }
};

bool cmp(StuInfo &a, StuInfo &b)
{
    return a.getId() < b.getId();
}

vector<StuInfo> stu;
vector<int> ids;

void QAQ()
{
    int id;
    string name;
    birth birthday;
    float score;
    char a;
    cin >> id >> name >> birthday.y >> a >> birthday.m >> a >> birthday.d >> score;
    StuInfo stu0;
    if (find(ids.begin(), ids.end(), id) != ids.end())
    {
        int pos = find(ids.begin(), ids.end(), id) - ids.begin();
        stu[pos].set(id, name, birthday, score);
    }
    else
    {
        stu0.set(id, name, birthday, score);
        stu.push_back(stu0);
        ids.push_back(id);
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < stu.size(); i++)
    {
        cout.fill('0');
        cout << "id:" << setw(4) << stu[i].getId() << " name:" << stu[i].getName() << " birthday:" << setw(4) << stu[i].getBirthday().y << "_" << stu[i].getBirthday().m << "_" << stu[i].getBirthday().d << " score:" << fixed << setprecision(1) << stu[i].getScore() << endl;
    }
    return 0;
}