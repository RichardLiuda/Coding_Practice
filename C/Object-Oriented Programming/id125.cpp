#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CTelNumber
{
private:
    char *p;

public:
    CTelNumber(char *s)
    {
        p = new char[strlen(s) + 1];
        strcpy(p, s);
    }
    CTelNumber(const CTelNumber &t)
    {
        bool flag = true;
        for (char *q = t.p; *q != '\0'; q++)
        {
            if (*q > '9' || *q < '0')
            {
                p = new char[21];
                strcpy(p, "Illegal phone number");
                flag = false;
                break;
            }
        }
        if (flag && strlen(t.p) == 7)
        {
            if (t.p[0] == '2' || t.p[0] == '3' || t.p[0] == '4')
            {
                p = new char[strlen(t.p) + 2];
                strcpy(p, "8");
                strcat(p, t.p);
            }
            else if (t.p[0] == '5' || t.p[0] == '6' || t.p[0] == '7' || t.p[0] == '8')
            {
                p = new char[strlen(t.p) + 2];
                strcpy(p, "2");
                strcat(p, t.p);
            }
            else
            {
                p = new char[21];
                strcpy(p, "Illegal phone number");
            }
        }
        else
        {
            p = new char[21];
            strcpy(p, "Illegal phone number");
        }
        cout << p << endl;
    }
    ~CTelNumber()
    {
        delete[] p;
    }
};

void QAQ()
{
    char *s = new char[8];
    cin >> s;
    CTelNumber t(s);
    CTelNumber t2(t);
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