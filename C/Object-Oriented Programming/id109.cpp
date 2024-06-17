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
    CList(int *value, int n)
    {
        head = new SNode;
        head->next = nullptr;
        head->data = 0;
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
    void removeNode()
    {
        SNode *q = head;
        while (q->next)
        {
            SNode *p = q->next;
            while (p->next)
            {
                if (p->next->data == q->next->data)
                {
                    if (p->next->next)
                    {
                        SNode *tmp = p->next;
                        p->next = tmp->next;
                        delete tmp;
                        continue;
                    }
                    else
                    {
                        p->next = nullptr;
                        break;
                    }
                }
                p = p->next;
            }
            q = q->next;
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
    int *num = new int[n];
    for (int i = 0; i < n; i++)
        cin >> num[i];
    CList lis(num, n);
    lis.removeNode();
    lis.printList();
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