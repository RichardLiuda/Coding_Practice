#include <stdio.h>

int main()
{
    // 读取t的值
    int t;
    scanf("%d", &t);
    // 当t不为0时，循环执行
    while (t--)
    {
        // 读取n的值
        int n;
        int m = 0;
        scanf("%d", &n);
        // 将n的值赋值给temp
        int temp = n;
        // 定义两个变量，分别记录n和m的长度
        int len1 = 0;
        int len2 = 0;
        // 当temp不为0时，循环执行
        while (temp != 0)
        {
            // 将m的值乘以10，再加上temp除以10的余数
            m *= 10;
            m += temp % 10;
            // 将temp除以10
            temp /= 10;
            // len1自增
            len1++;
        }
        // 将m的值赋值给temp
        temp = m;
        // 当temp不为0时，循环执行
        while (temp != 0)
        {
            // 将temp除以10
            temp /= 10;
            // len2自增
            len2++;
        }
        // 如果m除以n的余数为0，则输出n和m的值
        if (m % n == 0)
            printf("%d*%d=%d\n", n, m / n, m);
        // 否则，输出n，并将m的值前面补0，输出
        else
        {
            printf("%d ", n);
            for (int i = 0; i < len1 - len2; i++)
                printf("0");
            printf("%d\n", m);
        }
    }
    return 0;
}