#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class cnode
{
    int data;
    // 数据成员
    cnode *next; // next指针
public:
    // 构造函数
    cnode(int e = 0, cnode *nextval = nullptr)
    {
        data = e;
        next = nextval;
    }
    // 访问接口
    void setdata(int e) { data = e; }
    void setnext(cnode *nextval) { next = nextval; }
    int getdata() { return data; }
    cnode *getnext() { return next; }
};
// 带头结点
class clist
{
    cnode *head;

public:
    clist() { head = nullptr; }
    // constructor
    cnode *find(int i)
    {
        if (i < 0)
            return nullptr;
        int cnt = 0;
        cnode *p = head;
        while (p && cnt < i)
        {
            p = p->getnext();
            cnt++;
        }
        return p; // 传回对应元素的指针
    }
    // find by index
    bool insertlist(int i, int e)
    {
        cnode *p = find(i);
        if (p)
        {
            cnode *s = new cnode(e, p->getnext());
            p->setnext(s);
            return 1; // success
        }
        return 0; // failure
    }
    // insert
    bool deletelist(int i) // i从0开始
    {
        cnode *p = find(i - 1); // 找到前驱
        if (p && p->getnext())
        {
            cnode *q = p->getnext(); // 删除元素
            p->setnext(q->getnext());
            delete q;
            return 1;
        }
        return 0;
    }
    // delete
    void print()
    {
        cnode *p = head;
        while (p)
        {
            cout << p->getdata() << " ";
            p = p->getnext();
        }
        cout << endl;
    }
    // output
    cnode *findelement(int e)
    {
        cnode *p = head;
        while (p && p->getdata() != e)
            p = p->getnext();
        return p; // 传回对应元素的指针
    }
    // find by val

    // 尾插
    void createlist(int num[], int n)
    {
        cnode *tail = head;
        // tail始终指向表尾结点
        for (int i = 0; i < n; i++) // 依此插入每个数据
        {
            cnode *s = new cnode(num[i]);
            // 创建新结点
            if (head) // if(tail), 非空链表，插入tail结点之后
            {
                tail->setnext(s);
                tail = s;
            }
            else // 空链表，修改头指针和tail指针
            {
                head = tail = s;
            }
        }
    }
    // create list
};

void QAQ()
{
    clist l;
    int num[] = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    l.createlist(num, 13);
    l.print();
    l.deletelist(3);
    l.print();
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.in", "r", stdin);
    //     freopen("out.out", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}