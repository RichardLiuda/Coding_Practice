#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Health
{
private:
    string name;
    float high;
    float weigh;
    float girth;
    int BMI;
    float BFR;

public:
    void getName(string nameval) { name = nameval; }
    void getHigh(float highval) { high = highval; }
    void getWeigh(float weighval) { weigh = weighval; }
    void getGirth(float girthval) { girth = girthval; }
    void getBMI() { BMI = floor(weigh / (high * high) + 0.5); }
    void getBFR() { BFR = (girth * 0.74 - weigh * 0.082 - 34.89) / weigh; }
    void print()
    {
        cout << name << "'s BMI: " << BMI << "--BFR: " << setprecision(2) << BFR << endl;
    }
};

void QAQ()
{
    Health h;
    string nameval;
    float highval, weighval, girthval;
    cin >> nameval >> highval >> weighval >> girthval;
    h.getName(nameval);
    h.getHigh(highval);
    h.getWeigh(weighval);
    h.getGirth(girthval);
    h.getBMI(), h.getBFR();
    h.print();
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