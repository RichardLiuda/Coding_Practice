#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Matrix
{
    int n, m; // n行m列
    int **matrix;

public:
    Matrix(int n, int m, int **ma) : n(n), m(m)
    {
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = ma[i][j];
            }
        }
    }
    Matrix(Matrix &rhs)
    {
        n = rhs.m;
        m = rhs.n;
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                matrix[i][m - j - 1] = rhs.matrix[j][i];
            }
        }
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j];
                if (j != m - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < n; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};

void QAQ()
{
    int n, m;
    cin >> n >> m;
    int **ma = new int *[n];
    for (int i = 0; i < n; i++)
    {
        ma[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> ma[i][j];
        }
    }
    Matrix A(n, m, ma);
    cout << "before:" << endl;
    A.print();
    Matrix B(A);
    cout << "after:" << endl;
    B.print();
    for (int i = 0; i < n; i++)
    {
        delete[] ma[i];
    }
    delete[] ma;
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
        if (t)
            cout << endl;
    }
    return 0;
}