#include <bits/stdc++.h>
using namespace std;

struct student
{
    int rank;
    int score;
    int id;
} stu[11451];

bool cmp(student a, student b)
{
    if (a.score == b.score)
        return a.rank < b.rank;
    return a.score > b.score;
}

vector<vector<pair<int, int>>> ans(11451);

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> stu[j].id >> stu[j].score;
            stu[j].rank = j;
        }
        sort(stu, stu + n, cmp);
        for (int j = 0; j < n; j++)
        {
            ans[i].push_back(make_pair(stu[j].id, stu[j].score));
        }
    }
    for (auto i1 : ans)
        for (auto i2 : i1)
            cout << i2.first << " " << i2.second << endl;
    return 0;
}