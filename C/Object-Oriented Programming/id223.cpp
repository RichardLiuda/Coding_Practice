#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Document
{
    string name;

public:
    Document(string name)
    {
        this->name = name;
        cout << "Create Document Class" << endl;
    }
    void print()
    {
        cout << "Document Name is " << name << endl;
    }
    ~Document()
    {
        cout << "Delete Document Class" << endl;
    }
    string getName()
    {
        return name;
    }
};

class Book : public Document
{
    int pageCount;

public:
    Book(string name, int pageCount) : Document(name)
    {
        this->pageCount = pageCount;
        cout << "Create Book Class" << endl;
    }
    ~Book()
    {
        cout << "Delete Book Class" << endl;
    }
    void print()
    {
        Document::print();
        cout << "PageCount is " << pageCount << endl;
    }
};

void QAQ()
{
    string name;
    int pageCount;
    cin >> name >> pageCount;
    Book book(name, pageCount);
    book.print();
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