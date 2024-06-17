#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class CBook
{
private:
    string id, name;
    int renum, valnum;

public:
    CBook(string id, string name, int renum, int valnum) : id(id), name(name), renum(renum), valnum(valnum) {}
    string getId() { return id; }
    string getName() { return name; }
    int getRenum() { return renum; }
    int getValnum() { return valnum; }
    void setValnum(int valnum) { this->valnum = valnum; }
};

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    vector<CBook> book;
    while (n--)
    {
        string id, name;
        int renum, valnum;
        cin >> id >> name >> renum >> valnum;
        CBook cb(id, name, renum, valnum);
        book.push_back(cb);
    }
    cin >> m;
    vector<string> borb;
    while (m--)
    {
        string name;
        cin >> name;
        borb.push_back(name);
    }
    for (auto i : borb)
    {
        cout << i << " ";
        for (int j = 0; j < book.size(); j++)
        {
            if (book[j].getName() == i)
            {
                if (book[j].getValnum() > 0)
                {
                    cout << "索取号: " << book[j].getId() << endl;
                    book[j].setValnum(book[j].getValnum() - 1);
                }
                else
                    cout << "该书已全部借出" << endl;
                break;
            }
        }
    }
    cout << endl;
    int cnt = 0;
    int val = 0;
    for (auto i : book)
    {
        cout << i.getId() << " " << i.getName() << " " << i.getRenum() << " " << i.getValnum() << endl;
        cnt += i.getRenum() - i.getValnum();
        val += i.getValnum();
    }
    cout << "借出图书: " << cnt << "本  剩余馆藏图书: " << val << "本" << endl;
    return 0;
}