#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class SVP
{
private:
    int _type;
    string type;
    string name;
    int price;
    bool situa;

public:
    SVP(int _type, string name, int price, bool situa)
    {
        this->_type = _type;
        this->name = name;
        this->price = price;
        this->situa = situa;
    }
    void select()
    {
        switch (_type)
        {
        case 1:
            type = "BF";
            break;
        case 2:
            type = "CD";
            break;
        case 3:
            type = "VCD";
            break;
        case 4:
            type = "DVD";
            break;
        default:
            break;
        }
    }
    void Print()
    {
        cout << type << "[" << name << "]" << (situa ? "rented" : "not rented") << endl;
    }
    void Fee(int n)
    {
        cout << "Rental: " << n * price << endl;
    }
    bool getSitua() { return situa; }
};

void QAQ()
{
    int _type;
    string name;
    int price;
    bool situa;
    cin >> _type >> name >> price >> situa;
    SVP svp(_type, name, price, situa);
    int op;
    cin >> op;
    svp.select();
    svp.Print();
    if (op)
    {
        if (svp.getSitua())
            svp.Fee(op);
        else
            cout << "No rental" << endl;
    }
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
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