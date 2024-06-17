#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Cart;

class Goods
{
private:
    int id;
    string name;
    string color;
    string size;
    float price;
    int sum;

public:
    Goods(int id, string name, string color, string size, float price, int sum)
    {
        this->id = id;
        this->name = name;
        this->color = color;
        this->size = size;
        this->price = price;
        this->sum = sum;
    }
    float calPrice() { return price * sum; }
    friend Cart;
};

class Cart
{
private:
    vector<Goods> goods;
    int amount;
    float total;

public:
    Cart()
    {
        amount = 0;
        total = 0;
    }
    void add(Goods g)
    {
        auto pos = find_if(goods.begin(), goods.end(), [&](Goods &g1)
                           { return g1.id == g.id; });
        if (pos != goods.end())
        {
            (*pos).sum += g.sum;
            amount += g.sum;
        }
        else
            goods.push_back(g);
        amount += g.sum;
        total += g.calPrice();
    }
    void del(int id)
    {
        auto pos = find_if(goods.begin(), goods.end(), [&](Goods &g1)
                           { return g1.id == id; });
        amount -= (*pos).sum;
        total -= (*pos).calPrice();
        goods.erase(pos);
    }
    void up(int id)
    {
        auto pos = find_if(goods.begin(), goods.end(), [&](Goods &g1)
                           { return g1.id == id; });
        (*pos).sum++;
        amount++;
        total += (*pos).price;
    }
    void down(int id)
    {
        auto pos = find_if(goods.begin(), goods.end(), [&](Goods &g1)
                           { return g1.id == id; });
        if ((*pos).sum <= 1)
            return;
        (*pos).sum--;
        amount--;
        total -= (*pos).price;
    }
    void show()
    {
        cout << "商品清单:\n商品,颜色,尺码,单价,数量,小计" << endl;
        for (auto g = goods.end() - 1; g != goods.begin() - 1; g--)
        {
            cout << (*g).name << "," << (*g).color << "," << (*g).size << "," << fixed << setprecision(2) << (*g).price << "," << (*g).sum << "," << fixed << setprecision(2) << (*g).calPrice() << endl;
        }
        cout << "----------" << endl;
        cout << amount << "件商品,总商品金额" << fixed << setprecision(2) << total << endl;
    }
};

void QAQ()
{
    int n;
    cin >> n;
    Cart c;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == "ADD")
        {
            int id, sum;
            string name, color, size;
            float price;
            cin >> id >> name >> color >> size >> price >> sum;
            c.add(Goods(id, name, color, size, price, sum));
        }
        else if (op == "DELETE")
        {
            int id;
            cin >> id;
            c.del(id);
        }
        else if (op == "UP")
        {
            int id;
            cin >> id;
            c.up(id);
        }
        else if (op == "DOWN")
        {
            int id;
            cin >> id;
            c.down(id);
        }
    }
    c.show();
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