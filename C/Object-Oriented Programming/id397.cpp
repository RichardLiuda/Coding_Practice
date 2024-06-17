// 补充CBigInteger类和头文件
/********** Write your code here! **********/
#include <bits/stdc++.h>
using namespace std;

class CBigInteger
{
    string num;

public:
    CBigInteger()
    {
        num = "0";
    }
    CBigInteger(string str)
    {
        num = str;
    }
    CBigInteger operator+(CBigInteger &rhs)
    {
        bool neg = 0;
        if (this->num[0] == '-' && rhs.num[0] == '-')
        {
            *this->num.erase(this->num.begin());
            rhs.num.erase(rhs.num.begin());
            neg = 1;
        }
        else if (this->num[0] == '-')
        {
            *this->num.erase(this->num.begin());
            return rhs - *this;
        }
        else if (rhs.num[0] == '-')
        {
            rhs.num.erase(rhs.num.begin());
            return *this - rhs;
        }
        bool flag = 0;
        string res;
        for (int i = num.size() - 1, j = rhs.num.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int num1 = (i >= 0) ? num[i] - '0' : 0;
            int num2 = (j >= 0) ? rhs.num[j] - '0' : 0;
            res += (num1 + num2 + flag) % 10 + '0';
            flag = (num1 + num2 + flag) / 10;
        }
        if (flag)
            res += flag + '0';
        reverse(res.begin(), res.end());
        while (res[0] == '0' && res.size() > 1)
            res.erase(res.begin());
        if (neg)
            res = '-' + res;
        return CBigInteger(res);
    }
    CBigInteger operator-(CBigInteger &rhs)
    {
        if (this->num[0] == '-' && rhs.num[0] == '-')
        {
            *this->num.erase(this->num.begin());
            rhs.num.erase(rhs.num.begin());
            return rhs - *this;
        }
        else if (this->num[0] == '-')
        {
            rhs.num = '-' + rhs.num;
            return *this + rhs;
        }
        else if (rhs.num[0] == '-')
        {
            rhs.num.erase(rhs.num.begin());
            return *this + rhs;
        }
        if (stoi(this->num) < stoi(rhs.num))
        {
            CBigInteger tmp = rhs - *this;
            tmp.num = '-' + tmp.num;
            return tmp;
        }
        bool flag = 0;
        string res;
        for (int i = num.size() - 1, j = rhs.num.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int num1 = (i >= 0) ? num[i] - '0' : 0;
            int num2 = (j >= 0) ? rhs.num[j] - '0' : 0;
            res += (10 + num1 - num2 - flag) % 10 + '0';
            flag = (num1 - num2 - flag) < 0;
        }
        while (res[0] == '0' && res.size() > 1)
            res.erase(res.begin());
        if (flag)
            res += '-';
        reverse(res.begin(), res.end());
        return CBigInteger(res);
    }
    CBigInteger operator*(CBigInteger &rhs)
    {
        // string res;
        bool neg = 0;
        if (*this->num.begin() == '-' && rhs.num[0] == '-')
        {
            *this->num.erase(this->num.begin());
            rhs.num.erase(rhs.num.begin());
        }
        else if (*this->num.begin() == '-')
        {
            neg = 1;
            *this->num.erase(this->num.begin());
        }
        else if (rhs.num[0] == '-')
        {
            neg = 1;
            rhs.num.erase(rhs.num.begin());
        }
        CBigInteger res;
        for (int i = rhs.num.size() - 1; i >= 0; i--)
        {
            CBigInteger tmp;
            int num1 = rhs.num[i] - '0';
            if (num1 == 0)
                continue;
            for (int j = 1; j <= num1; j++)
                tmp = tmp + *this;
            for (int k = rhs.num.size() - 1; k > i; k--)
                tmp.num += '0';
            // res = tmp.num + res;
            res = res + tmp;
        }
        if (neg)
            res.num = '-' + res.num;
        return res;
    }
    friend ostream &operator<<(ostream &os, const CBigInteger &rhs);
    friend istream &operator>>(istream &is, CBigInteger &rhs);
};

ostream &operator<<(ostream &os, const CBigInteger &rhs)
{
    string ans = rhs.num;
    while (ans[0] == '0' && ans.size() > 1)
    {
        ans.erase(ans.begin());
    }
    os << (rhs.num[0] == '-' ? "(" : "") << (ans.empty() ? rhs.num : ans) << (rhs.num[0] == '-' ? ")" : "");
    return os;
}

istream &operator>>(istream &is, CBigInteger &rhs)
{
    is >> rhs.num;
    return is;
}

/*******************************************/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t;
    char op;
    CBigInteger bigNum1;
    CBigInteger bigNum2;

    cin >> t;
    while (t--)
    {
        cin >> bigNum1 >> op >> bigNum2;
        cout << bigNum1 << " " << op << " " << bigNum2 << " = ";
        if (op == '+')
            cout << bigNum1 + bigNum2 << endl;
        else if (op == '-')
            cout << bigNum1 - bigNum2 << endl;
        else if (op == '*')
            cout << bigNum1 * bigNum2 << endl;
    }
    return 0;
}
