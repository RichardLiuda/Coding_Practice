#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class STR
{
private:
    char *s;
    void backward(char *t1, char *t2)
    {
        while (t2 - t1 > 0)
        {
            swap(*t2, *t1);
            t2--, t1++;
        }
    }

public:
    STR(char *t)
    {
        s = t;
        cout << "constructing..." << endl;
    }
    STR(const STR &obj)
    {
        s = new char[strlen(obj.s) + 1];
        strcpy(s, obj.s);
        cout << "copy constructing..." << endl;
    }
    void fun()
    {
        char *t1 = s, *t2 = s;
        while (*t2 != '\0')
        {
            while (*(t2 + 1) != ' ' && *(t2 + 1) != '\0')
                t2++;
            backward(t1, t2++);
            if (*t2 != '\0')
                t1 = ++t2;
        }
    }
    void print()
    {
        cout << s;
    }
    STR(STR &rhs)
    {
        s = new char[strlen(rhs.s) + 1];
        strcpy(s, rhs.s);
        cout << "copy constructing..." << endl;
    }
    ~STR()
    {
        cout << "delete space..." << endl;
        delete[] s;
    }
};

void QAQ()
{
    string s;
    getline(cin, s);
    char *t = new char[s.length() + 1];
    const char *t = s.c_str();
    char *t = new char[s.length() + 1];
    strcpy(t, s.c_str());
    STR a(t);
    STR b(a);
    a.print();
    b.fun();
    cout << " can be tranformed to ";
    b.print();
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}