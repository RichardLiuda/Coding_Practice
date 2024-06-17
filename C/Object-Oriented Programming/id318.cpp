#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Cset
{
    int n;
    int *data;

public:
    friend istream &operator>>(istream &in, Cset &s);
    friend ostream &operator<<(ostream &out, Cset &s);
    Cset operator+(const Cset &s)
    {
        Cset ans;
        ans.n = 0;
        ans.data = new int[this->n + s.n];
        for (int i = 0; i < this->n; i++)
        {
            ans.data[ans.n++] = this->data[i];
        }
        for (int i = 0; i < s.n; i++)
        {
            if (find(ans.data, ans.data + ans.n, s.data[i]) == ans.data + ans.n)
                ans.data[ans.n++] = s.data[i];
        }
        return ans;
    }
    Cset operator*(const Cset &s)
    {
        Cset ans;
        ans.n = 0;
        ans.data = new int[min(this->n, s.n)];
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < s.n; j++)
            {
                if (this->data[i] == s.data[j])
                {
                    ans.data[ans.n++] = this->data[i];
                }
            }
        }
        return ans;
    }
    Cset operator-(const Cset &s)
    {
        Cset ans;
        ans.n = 0;
        ans.data = new int[max(this->n, s.n)];
        for (int i = 0; i < this->n; i++)
        {
            if (find(s.data, s.data + s.n, this->data[i]) == s.data + s.n)
            {
                ans.data[ans.n++] = this->data[i];
            }
        }
        return ans;
    }
};

istream &operator>>(istream &in, Cset &s)
{
    in >> s.n;
    s.data = new int[s.n];
    for (int i = 0; i < s.n; i++)
    {
        in >> s.data[i];
    }
    return in;
}

ostream &operator<<(ostream &out, Cset &s)
{
    for (int i = 0; i < s.n; i++)
        out << s.data[i] << (i == s.n - 1 ? "" : " ");
    out << endl;
    return out;
}

void QAQ()
{
    Cset a, b;
    cin >> a >> b;
    Cset c = a + b;
    Cset d = a * b;
    Cset e = (a - b) + (b - a);
    cout << "A:" << a;
    cout << "B:" << b;
    cout << "A+B:" << c;
    cout << "A*B:" << d;
    cout << "(A-B)+(B-A):" << e;
    cout << endl;
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



