#include <stdio.h>

int tri(int n){
    return n*n*n;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for(a; a <= b; a++){
        if(a==tri(a%10)+tri(a%100/10)+tri(a/100))
            printf("%d\n", a);
    }
    return 0;
}
