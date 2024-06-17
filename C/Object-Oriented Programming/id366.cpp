#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
int cnt = 0;

class Robot
{
private:
    string name;
    int hp, dam, def;
    string type;
    int lev;

public:
    Robot(string _name, string _type, int _lev)
    {
        name = _name;
        type = _type;
        lev = _lev;
        setVal(_type);
    }
    void setVal(string type)
    {
        hp = 5 * lev;
        dam = 5 * lev;
        def = 5 * lev;
        if (type == "A")
            dam *= 2;
        else if (type == "D")
            def *= 2;
        else if (type == "H")
            hp *= 10;
    }
    string getName() { return name; }
    string getType() { return type; }
    int getHp() { return hp; }
    int getDam() { return dam; }
    int getDef() { return def; }
    int getLev() { return lev; }
    void setName(string name) { this->name = name; }
    void setType(string type) { this->type = type; }
    void setHp(int hp) { this->hp = hp; }
    void setDam(int dam) { this->dam = dam; }
    void setDef(int def) { this->def = def; }
    void setLev(int lev) { this->lev = lev; }
    void print()
    {
        cout << name << "--" << type << "--" << lev << "--" << hp << "--" << dam << "--" << def << endl;
    }
    ~Robot() {}
};

bool gaiya(Robot *r, string type)
{
    if (r->getType() != type)
    {
        r->setType(type);
        r->setVal(type);
        cnt++;
        return true;
    }
    return false;
}

void QAQ()
{
    string name, type;
    int lev;
    cin >> name >> type >> lev;
    Robot *r = new Robot(name, type, lev);
    cin >> type;
    gaiya(r, type);
    r->print();
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
    cout << "The number of robot transform is " << cnt << endl;
    return 0;
}