#include <iostream>
using namespace std;

char ch;
int t;
int n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        getchar();
        scanf("%c", &ch);
        if (ch == 'I')
        {
            int *arr = new int;
            scanf("%d", &n);
            int sum;
            for (int i = 0; i < n; i++)
            {
                scanf("%d", arr + i);
                sum += *(arr + i);
            }
            printf("%g\n", 1.0 * sum / n);
            // delete[] arr;
        }
        else if (ch == 'C')
        {
            char *arr = new char;
            scanf("%d", &n);
            char max = 'A';
            for (int i = 0; i < n; i++)
            {
                getchar();
                scanf("%c", arr + i);
                if (*(arr + i) > max)
                    max = *(arr + i);
            }
            printf("%c\n", max);
            // delete[] arr;
        }
        else if (ch == 'F')
        {
            float *arr = new float;
            scanf("%d", &n);
            float min = 1e3;
            for (int i = 0; i < n; i++)
            {
                scanf("%f", arr + i);
                if (*(arr + i) < min)
                    min = *(arr + i);
            }
            printf("%g\n", min);
            // delete[] arr;
        }
    }
    return 0;
}