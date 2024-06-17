#include <iostream>
using namespace std;
// 根据主函数代码完成以下填空
/********** Write your code here! **********/
#include <bitset>
#include <string>

template <int bits>
class MyBitset
{
    long num;
    bitset<bits> bin;

public:
    MyBitset(long num)
    {
        this->num = num;
        bin = bitset<bits>(num);
    }
    template <int bit>
    friend istream &operator>>(istream &in, MyBitset<bit> &b);
    template <int bit>
    friend ostream &operator<<(ostream &out, const MyBitset<bit> &b);
    MyBitset<bits> &operator<<=(int offset)
    {
        // bool flag = 0;
        // if (bin[bits - 1] == 1)
        // {
        //     int _num = ~num + 1;
        //     bin = bitset<bits>(_num);
        //     flag = 1;
        // }
        for (int i = 1; i <= offset; i++)
        {
            for (int j = bits - 1; j >= 0; j--)
            {
                if (j == 0)
                    bin[j] = 0;
                else
                    bin[j] = bin[j - 1];
            }
            // cout << bin << endl;
        }
        // if (flag)
        // {
        //     bin.flip();
        //     int i = 0;
        //     if (!bin[i])
        //         bin.flip(i++);
        //     while (bin[i])
        //     {
        //         bin.flip(i++);
        //     }
        //     bin.flip(i);
        // }
        return *this;
    }
    MyBitset<bits> &operator>>=(int offset)
    {
        for (int i = 1; i <= offset; i++)
        {
            for (int j = 0; j <= bits - 1; j++)
            {
                if (j == bits - 1)
                    bin[j] = 0;
                else
                    bin[j] = bin[j + 1];
            }
            // cout << bin << endl;
        }
        return *this;
    }
};

template <int bits>
istream &operator>>(istream &in, MyBitset<bits> &b)
{
    in >> b.num;
    return in;
}

template <int bits>
ostream &operator<<(ostream &out, const MyBitset<bits> &b)
{
    out << b.bin;
    return out;
}
/*******************************************/
// 主函数
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n, offset;
    long num;
    string mode;
    cin >> n;
    while (n--)
    {
        cin >> num >> mode >> offset;

        MyBitset<16> bit16(num);
        MyBitset<32> bit32(num);
        MyBitset<64> bit64(num);

        auto f_printbits = [&]() { // c++11以上
            cout << bit16 << endl
                 << bit32 << endl
                 << bit64 << endl
                 << endl;
        };
        f_printbits();
        if (mode == ">>")
        {
            bit16 >>= offset;
            bit32 >>= offset;
            bit64 >>= offset;
        }
        else if (mode == "<<")
        {
            bit16 <<= offset;
            bit32 <<= offset;
            bit64 <<= offset;
        }
        f_printbits();
    } // end while
    return 0;
}
