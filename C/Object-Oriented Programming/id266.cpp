#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Animal
{
private:
    int weight;

public:
    Animal() {}
    Animal(int weight)
    {
        this->weight = weight;
    }
    void print()
    {
        cout << "weight:" << weight << endl;
    }
    ~Animal() {}
};

class Horse : virtual public Animal
{
private:
    int Distance;

public:
    Horse(int weight, int Distance) : Animal(weight), Distance(Distance) {}
    Horse(int Distance)
    {
        this->Distance = Distance;
    }
    void print()
    {
        Animal::print();
        cout << "distance:" << Distance << endl;
    }
    void _print()
    {
        cout << "distance:" << Distance << endl;
    }
    ~Horse() {}
};

class Bird : virtual public Animal
{
private:
    int Height;

public:
    Bird(int weight, int Height) : Animal(weight), Height(Height) {}
    Bird(int Height)
    {
        this->Height = Height;
    }
    void print()
    {
        Animal::print();
        cout << "Height:" << Height << endl;
    }
    void _print()
    {
        cout << "Height:" << Height << endl;
    }
    ~Bird() {}
};

class Pegasus : public Horse, public Bird
{
private:
    bool state;

public:
    Pegasus(int weight, int Distance, int Height, bool state) : Animal(weight), Horse(Distance), Bird(Height), state(state) {}
    void print()
    {
        Animal::print();
        Horse::_print();
        Bird::_print();
    }
    bool getState()
    {
        return state;
    }
};

void QAQ()
{
    int w, d, h, s;
    cin >> w >> d >> h >> s;
    Animal a(w);
    cout << "Animal:" << endl;
    a.print();
    cout << endl;
    Horse _h(w, d);
    cout << "Horse:" << endl;
    _h.print();
    cout << endl;
    Bird b(w, h);
    cout << "Bird:" << endl;
    b.print();
    cout << endl;
    Pegasus p(w, d, h, s);
    cout << "Pegasus:" << endl;
    p.print();
    cout << "In the air?" << endl
         << (p.getState() ? "true" : "false") << endl;
    cout << "On land?" << endl
         << (!p.getState() ? "true" : "false") << endl;
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
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}