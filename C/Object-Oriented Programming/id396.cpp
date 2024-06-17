#include <cstring>
#include <iostream>
using namespace std;

class CString
{
    char *s;
    int n;

public:
    CString(char *const _s = nullptr) : s(nullptr), n(0)
    {
        if (!_s)
            return;
        n = strlen(_s);
        s = new char[n + 1]{};
        strncpy(s, _s, n); // 记得 #include <cstring>
    }
    ~CString()
    {
        delete[] s;
    }

    // 1. 要求重载 '+' 运算符, 实现两个CString对象相加的结果
    //   （不能改变原来的两个CString对象）
    // ...可以补充其它成员函数...

    /********** Write your code here! **********/
    CString operator+(CString &s2)
    {
        if (s2.s == nullptr)
            return *this;
        else if (s == nullptr)
            return s2;
        CString s3;
        s3.n = n + s2.n;
        s3.s = new char[s3.n + 1];
        strcpy(s3.s, s);
        strcpy(s3.s + n, s2.s);
        return s3;
    }
    CString operator=(const CString &s2)
    {
        if (&s2 == this)
            return *this;
        if (s)
            delete[] s;
        n = s2.n;
        s = new char[s2.n + 1];
        strcpy(s, s2.s);
        return *this;
    }
    CString(const CString &rhs)
    {
        n = rhs.n;
        s = new char[n];
        strcpy(s, rhs.s);
    }
    friend ostream &operator<<(ostream &out, const CString &s);
};

ostream &operator<<(ostream &out, const CString &s)
{
    out << s.s;
    return out;
}
/*******************************************/
int main()
{
    int n;
    char input[64 + 1]{}; // ! strlen(s) + 1
    cin >> n;
    while (n--)
    {
        cin >> input;
        CString s1(input);
        cin >> input;
        CString s2(input);

        CString sEmpty;                   // !
        delete new CString(s1 = s1 + s2); // !

        cout << s1 + sEmpty << endl
             << sEmpty + s2 << endl
             << s1 + s2 << endl
             << endl;
    }
    return 0;
}