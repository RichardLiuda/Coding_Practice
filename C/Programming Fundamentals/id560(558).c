#include<stdio.h>

char arr[1145];
char *p;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int sum=0;
        scanf("%s",&arr);
        p=arr;
        while(*p!='\0'){
            p++;
            sum++;}
            printf("%d\n",sum);
    }
    return 0;
}