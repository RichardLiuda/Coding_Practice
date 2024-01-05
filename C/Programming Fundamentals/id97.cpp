#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    char c;
    cin >> c;
    if (c == 'A')
        cout << "一个学期的努力给你带来了应有的收获";
    else if (c == 'B')
        cout << "你与成功还缺少了一点契机";
    else if (c == 'C')
        cout << "保底已到，力争上游";
    else if (c == 'D')
        cout << "失败与你只是一步之遥，莫一失足成千古恨";
    else if (c == 'F')
        cout << "一次失败代表不了什么，请从头再来";
    return 0;
}
