// 补齐头文件 及要求的类
/********** Write your code here! **********/
#include <bits/stdc++.h>
using namespace std;

class CInternetBankCustomer;
class CBankCustomer;
class CInternetBankCustomer;

class CPeople
{
protected:
    string id, name;
};

class CInternetUser : public CPeople
{
protected:
    string password;

public:
    void registerUser(string name, string id, string password)
    {
        this->name = name;
        this->id = id;
        this->password = password;
    }
    bool login(string id, string password)
    {
        if (id == this->id && password == this->password)
            return 1;
        else
            return 0;
    }
    // string getId()
    // {
    //     return id;
    // }
    // string getName()
    // {
    //     return name;
    // }
};

class CBankCustomer : public CPeople
{
protected:
    double balance;

public:
    CBankCustomer() : balance(0) {}
    void openAccount(string name, string id)
    {
        this->name = name;
        this->id = id;
        balance = 0;
    }
    bool deposit(double money)
    {
        if (money > 0)
        {
            balance += money;
            return 1;
        }
        else
            return 0;
    }
    bool withdraw(double money)
    {
        if (money > 0 && money <= balance)
        {
            balance -= money;
            return 1;
        }
        else
            return 0;
    }
    // bool check(CInternetBankCustomer *c)
    // {
    //     if (this->name == c->getName() && this->id == c->getId())
    //         return 1;
    //     else
    //         return 0;
    // }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer
{
    double balance, bef_balance, tod_interest, tod_winterest, bef_winterest;

public:
    CInternetBankCustomer() : CBankCustomer(), balance(0), bef_balance(0), tod_winterest(0) {}
    bool deposit(double money)
    {
        if (CBankCustomer::withdraw(money))
        {
            balance += money;
            return 1;
        }
        else
            return 0;
    }
    bool withdraw(double money)
    {
        if (balance >= money)
        {
            if (CBankCustomer::deposit(money))
            {
                balance -= money;
                return 1;
            }
        }
        return 0;
    }
    void setInterest(double interest)
    {
        bef_winterest = tod_winterest;
        tod_winterest = interest;
        tod_interest = bef_winterest * bef_balance / 10000;
    }
    void calculateProfit()
    {
        balance += tod_interest;
        bef_balance = balance;
    }
    bool login(string id, string password)
    {
        return CInternetUser::login(id, password) && CBankCustomer::name == CInternetUser::name && CInternetUser::id == CBankCustomer::id;
    }
    void print()
    {
        cout << "Name: " << CBankCustomer::name << " " << "ID: " << CBankCustomer::id << "\n"
             << "Bank balance: " << CBankCustomer::balance << "\n"
             << "Internet bank balance: " << balance << "\n";
        cout << endl;
    }
};
/*******************************************/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int t, no_of_days, i;
    string i_xm, i_id, i_mm, b_xm, b_id, ib_id, ib_mm;
    double money, interest;
    char op_code;

    // 输入测试案例数t
    cin >> t;
    while (t--)
    {
        // 输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

        // 输入银行开户用户名,id
        cin >> b_xm >> b_id;

        // 输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0) // 互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        // 输入天数
        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++)
        {
            // 输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S': // 从银行向互联网金融帐户存入
            case 's':
                if (ib_user.deposit(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T': // 从互联网金融转入银行帐户
            case 't':
                if (ib_user.withdraw(money) == 0)
                {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D': // 直接向银行帐户存款
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': // 直接从银行帐户取款
            case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0)
                {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            // 输出用户名,id
            // 输出银行余额
            // 输出互联网金融账户余额
            ib_user.print();
        }
    }
}
