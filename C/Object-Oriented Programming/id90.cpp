#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class lottery
{
private:
    int *group1 = new int[6];
    int num;
    int **groupn = new int *[9];

public:
    void print()
    {
        for (int i = 0; i < 6; i++)
            cout << group1[i] << (i == 5 ? "\n" : " ");
        // cout << endl;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < 6; j++)
                cout << groupn[i][j] << (j == 5 ? "\n" : " ");
            // cout << endl;
        }
    }
    lottery(int group[], int num)
    {
        group1 = new int[6];
        groupn = new int *[9];
        for (int i = 0; i < 6; i++)
            group1[i] = group[i];
        this->num = num;
    }
    lottery(lottery &l)
    {
        for (int i = 0; i < 6; i++)
        {
            group1[i] = l.group1[i];
        }
        num = l.num;

        for (int i = 0; i < num; i++)
            groupn[i] = new int[6];
        for (int i = 0; i < 6; i++)
        {
            if (i == 0)
                groupn[0][i] = group1[5] + 1;
            else
                groupn[0][i] = group1[i - 1] + 1;
        }
        for (int i = 1; i < num; i++)
            for (int j = 0; j < 6; j++)
            {
                if (j == 0)
                    groupn[i][j] = groupn[i - 1][5] + 1;
                else
                    groupn[i][j] = groupn[i - 1][j - 1] + 1;
            }
    }
    ~lottery()
    {
        delete[] (group1);
        // for (int i = 0; i < num; i++)
        //     delete[] (groupn[i]);
        delete[] (groupn);
    }
};

void QAQ()
{
    int group[6];
    int num;
    for (int i = 0; i < 6; i++)
        cin >> group[i];
    cin >> num;
    lottery l(group, num);
    lottery l1(l);
    l1.print();
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.in", "r", stdin);
    //     freopen("out.out", "w", stdout);
    // #endif
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