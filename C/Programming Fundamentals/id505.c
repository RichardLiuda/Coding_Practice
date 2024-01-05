#include <stdio.h>
#include <string.h>
#define SIZE 10
//请补充itostr函数的实现
void itostr(int num, char str[])
{
    /********** Write your code here! **********/
    //如果num是0，直接将str赋值为"0"，然后返回
    // if (num == 0)
    // {
    //     strcpy(str, "0");
    //     return;
    // }
    // //定义一个静态变量index，用来记录str的当前位置
    // static int index = 0;
    // //如果num是负数，先在str的第一个位置放一个负号，然后取num的绝对值
    // if (num < 0)
    // {
    //     str[0] = '-';
    //     index = 1;
    //     num = -num;
    // }
    // //如果num是个位数，说明递归结束，需要在str的index位置加上空字符，然后返回
    // if (num / 10 == 0)
    // {
    //     str[index] = num % 10 + '0';
    //     str[index + 1] = '\0';
    //     //将index重置为0，为下一次调用做准备
    //     index = 0;
    //     return;
    // }
    // //递归调用itostr，将num的除以10的商作为参数
    // itostr(num / 10, str);
    // //将num的余数转换为字符，放在str的index位置
    // str[index] = num % 10 + '0';
    // //将index加一，为下一位数字做准备
    // index++;
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    for (int i = 0; i < 10; i++)
    {
        if (str[i] != '-' && !(str[i] <= '9' && str[i] >= '0'))
        {
            str[i] = '\0';
            break;
        }
    }
    if (num == 0)
    {
        int flag = 1;
        for (int i = 0; i < 10; i++)
        {
            if (str[i] == '\0')
                break;
            if (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
            {
                flag--;
                break;
            }
        }
        if (flag)
        {
            str[0] = '0';
            str[1] = '\0';
        }
        printf("%s", str);
        str[0] = str[1] = '\0';
        return;
    }
    char c = num % 10 + '0';
    char temp[20];
    temp[0] = c;
    temp[1] = '\0';
    if (str[0] != '-')
    {
        strcat(temp + 1, str);
        strcpy(str, temp);
    }
    else
    {
        strcat(temp + 1, str + 1);
        strcpy(str + 1, temp);
    }
    num /= 10;

    itostr(num, str);
    return;

    /*******************************************/
}
int main()
{
    int t, num;
    char str[SIZE];

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &num);
        itostr(num, str);
        printf("%s\n", str);
    }
}