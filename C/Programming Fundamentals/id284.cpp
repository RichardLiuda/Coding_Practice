#include <iostream>
using namespace std;

int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    for (int i = 9; i >= 0; i--)
    {
        if (i == 0)
        {
            printf("%d", a[i]);
        }
        else
        {
            printf("%d ", a[i]);
        }
    }

    return 0;
}