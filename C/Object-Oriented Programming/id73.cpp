#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Student
{
private:
    string name;
    string id;
    string college;
    string major;
    string sex;
    string address;
    string phonenum;

public:
    void setName(string nameval)
    {
        name = nameval;
    }
    void setId(string idval)
    {
        id = idval;
    }
    void setCollege(string collegeval)
    {
        college = collegeval;
    }
    void setMajor(string majorval)
    {
        major = majorval;
    }
    void setSex(string sexval)
    {
        sex = sexval;
    }
    string getName()
    {
        return name;
    }
    string getId()
    {
        return id;
    }
    string getCollege()
    {
        return college;
    }
    string getMajor()
    {
        return major;
    }
    string getSex()
    {
        return sex;
    }
    string getAddress()
    {
        return address;
    }
    string getPhonenum()
    {
        return phonenum;
    }
};

void QAQ()
{
    Student stu;
    string nameval, idval, collegeval, majorval, sexval, addressval, phonenumval;
    cin >> nameval >> idval >> collegeval >> majorval >> sexval >> addressval >> phonenumval;
    stu.setName(nameval);
    stu.setId(idval);
    stu.setCollege(collegeval);
    stu.setMajor(majorval);
    stu.setSex(sexval);
    stu.setAddress(addressval);
    stu.setPhonenum(phonenumval);
    cout << stu.getName() << " " << stu.getId() << " " << stu.getCollege() << " " << stu.getMajor() << " " << stu.getSex() << " " << stu.getAddress() << " " << stu.getPhonenum() << endl;
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