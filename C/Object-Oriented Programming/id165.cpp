#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Customer
{
private:
    static int TotalCustNum;
    static int Rent;
    static int Year;
    int CustID;
    char *CustName;

public:
    Customer(char *name)
    {
        CustID = ++TotalCustNum;
        CustName = new char[strlen(name) + 1];
        strcpy(CustName, name);
    }
    ~Customer()
    {
        delete CustName;
    }
    static void changeyear(int r) { Year = r; }
    void Display()
    {
        cout.fill('0');
        cout << CustName << " " << Year << setw(4) << CustID << " " << TotalCustNum << " " << Rent << endl;
        Rent += 150;
    }
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 150;
int Customer::Year = 2014;

void QAQ()
{
    int year;
    cin >> year;
    Customer::changeyear(year);
    while (1)
    {
        char *name = new char[114];
        cin >> name;
        if (name[0] == '0')
            break;
        Customer c(name);
        c.Display();
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