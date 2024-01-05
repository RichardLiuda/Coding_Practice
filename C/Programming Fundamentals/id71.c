#include <stdio.h>

int main()
{
    int a,b;
    char c;
    scanf("%x%c%x",&a,&c,&b);
    switch(c){
        case '+':
            printf("%o\n",a+b);
            break;
        case '-':
            printf("%o\n",a-b);
            break;
    }
    return 0;
}