#include <iostream>
using namespace std;

class RMB;
ostream &operator<<(ostream &, RMB &);
istream &operator>>(istream &, RMB &);

class RMB
{
protected:
    int yuan, jiao, fen;

public:
    RMB(double a = 0.0);
    RMB(int, int, int);
    bool operator>(RMB &);
    friend ostream &operator<<(ostream &, RMB &); // 一行输出，无换行
    friend istream &operator>>(istream &, RMB &);
    friend RMB operator+(RMB &, RMB &);
};
// 完成以下类定义的填空
/********** Write your code here! **********/
RMB::RMB(double a)
{
    yuan = (int)(a + 0.005);
    jiao = (int)((a - yuan) * 10 + 0.005);
    fen = (int)(((a - yuan) * 10 - jiao) * 10 + 0.005);
}
RMB::RMB(int y, int j, int f) : yuan(y), jiao(j), fen(f) {}
bool RMB::operator>(RMB &rhs)
{
    if (yuan == rhs.yuan)
    {
        if (jiao == rhs.jiao)
        {
            return fen > rhs.fen;
        }
        return jiao > rhs.jiao;
    }
    return yuan > rhs.yuan;
}
ostream &operator<<(ostream &out, RMB &a)
{
    out << a.yuan << "yuan" << a.jiao << "jiao" << a.fen << "fen";
    return out;
}
istream &operator>>(istream &in, RMB &a)
{
    in >> a.yuan >> a.jiao >> a.fen;
    return in;
}
RMB operator+(RMB &a, RMB &b)
{
    return RMB(((a.fen + b.fen >= 1) ? (a.jiao + b.jiao + 1) : (a.jiao + b.jiao)) >= 10 ? a.yuan + b.yuan + 1 : a.yuan + b.yuan, (a.fen + b.fen >= 10) ? (a.jiao + b.jiao + 1) % 10 : (a.jiao + b.jiao) % 10, (a.fen + b.fen) % 10);
}
/*******************************************/
// 主函数
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    double val_yuan;
    cin >> t;
    while (t--)
    {
        cin >> val_yuan;  // 输入一个浮点数，例如1.23
        RMB r1(val_yuan); // 例如上一行输入1.23，则生成对象r1是1元2角3分
        RMB r2;
        cin >> r2; // 输入一行三个整数参数，按元、角、分输入

        if (r1 > r2)
            cout << r1 << " > " << r2 << endl;
        else
            cout << r1 << " <= " << r2 << endl;
        RMB r3 = r1 + r2;
        cout << r1 << " + " << r2 << " = " << r3 << endl;
    }
    return 0;
}
