#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

template <class T>
class Matrix
{
    int m, n; // m lines & n columns
    T **ma;
    T **_ma;

public:
    Matrix(int m, int n, T **a) : m(m), n(n)
    {
        ma = new T *[m];
        for (int i = 0; i < m; i++)
            ma[i] = new T[n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ma[i][j] = a[i][j];
    }
    void transport()
    {
        _ma = new T *[n];
        for (int i = 0; i < n; i++)
            _ma[i] = new T[m];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                _ma[j][i] = ma[i][j];
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << _ma[i][j] << (j == m - 1 ? "" : " ");
            cout << endl;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < m; i++)
            delete[] ma[i];
        delete[] ma;
        for (int i = 0; i < n; i++)
            delete[] _ma[i];
        delete[] _ma;
    }
};

void QAQ()
{
    char op;
    int m, n;
    cin >> op >> m >> n;
    if (op == 'I')
    {
        int **ma = new int *[m];
        for (int i = 0; i < m; i++)
        {
            ma[i] = new int[m];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ma[i][j];
            }
        }
        Matrix<int> a(m, n, ma);
        a.transport();
        a.print();
    }
    else if (op == 'D')
    {
        double **ma = new double *[m];
        for (int i = 0; i < m; i++)
        {
            ma[i] = new double[m];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ma[i][j];
            }
        }
        Matrix<double> a(m, n, ma);
        a.transport();
        a.print();
    }
    else if (op == 'C')
    {
        char **ma = new char *[m];
        for (int i = 0; i < m; i++)
        {
            ma[i] = new char[m];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ma[i][j];
            }
        }
        Matrix<char> a(m, n, ma);
        a.transport();
        a.print();
    }
    else if (op == 'S')
    {
        string **ma = new string *[m];
        for (int i = 0; i < m; i++)
        {
            ma[i] = new string[m];
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> ma[i][j];
            }
        }
        Matrix<string> a(m, n, ma);
        a.transport();
        a.print();
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
    cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}