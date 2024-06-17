#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CBook
{
    string name, writer;
    double price;
    string publisher;

public:
    friend void find(CBook *book, int n, int &max1index, int &max2index);
    CBook() {}
    friend ostream &operator<<(ostream &out, CBook &book);
    friend istream &operator>>(istream &in, CBook &book);
};

ostream &operator<<(ostream &out, CBook &book)
{
    out << book.name << "\n"
        << book.writer << "\n"
        << fixed << setprecision(2) << book.price << "\n"
        << book.publisher << endl;
    return out;
}
istream &operator>>(istream &in, CBook &book)
{
    getline(in, book.name, ',');
    getline(in, book.writer, ',');
    in >> book.price;
    in.get();
    getline(in, book.publisher);
    return in;
}
void find(CBook *book, int n, int &max1index, int &max2index)
{
    int maxx = 0;
    for (int i = 0; i < n; i++)
    {
        if (book[i].price >= maxx)
        {
            maxx = book[i].price;
            max2index = max1index;
            max1index = i;
        }
    }
    if (book[max1index].price == book[max2index].price)
    {
        swap(max1index, max2index);
    }
}

void QAQ()
{
    int n;
    cin >> n;
    CBook *book = new CBook[n];
    for (int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    int max1index = -1, max2index = -1;
    find(book, n, max1index, max2index);
    cout << book[max1index] << "\n"
         << book[max2index];
    delete[] book;
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