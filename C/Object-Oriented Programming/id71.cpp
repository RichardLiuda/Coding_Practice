#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct SNode

{
    int data;
    SNode *next;
};

class CList
{
private:
    SNode *head;

public:
    CList()
    {
        head = new SNode;
        head->next = nullptr;
        head->data = 0;
    }
    void createList(int *value, int n)
    {
        SNode *q = head;
        for (int i = 0; i < n; i++)
        {
            SNode *p = new SNode;
            p->data = value[i];
            q->next = p;
            q = p;
        }
        q->next = nullptr;
    }
    void printList()
    {
        SNode *p = head->next;
        while (p != nullptr)
        {
            cout << p->data << (p->next ? " " : "\n");
            p = p->next;
        }
    }
    bool insertNode(int pos, int value)
    {
        if (pos < 0)
            return 0;
        SNode *p = head;
        int cnt = 0;
        while (p && cnt < pos)
        {
            p = p->next;
            cnt++;
        }
        if (!p)
            return 0;
        SNode *ins = new SNode;
        *ins = {value, p->next};
        p->next = ins;
        return 1;
    }
    bool removeNode(int pos)
    {
        if (pos <= 0)
            return 0;

        else
        {
            SNode *p = head;
            int cnt = 0;
            while (p && cnt < pos - 1)
            {
                p = p->next;
                cnt++;
            }
            if (!p)
                return 0;
            if (p->next)
            {
                SNode *tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                return 1;
            }
            return 0;
        }
    }
    ~CList()
    {
        SNode *p = head;
        while (p)
        {
            SNode *q = p;
            p = q->next;
            delete q;
        }
    }
};

void QAQ()
{
    int n;
    cin >> n;
    CList lis;
    int *num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    lis.createList(num, n);
    lis.printList();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int pos, val;
        cin >> pos >> val;
        if (!lis.insertNode(pos, val))
            cout << "error" << endl;
        else
            lis.printList();
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int pos;
        cin >> pos;
        if (!lis.removeNode(pos))
            cout << "error" << endl;
        else
            lis.printList();
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