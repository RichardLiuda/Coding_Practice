#include<stdio.h>
char a[114][114]={"ass","we","can"};
int sum=0;

void f(char **a,int n,int m){
    int sum=0;
    for(int i=0;i<3;i++){
    for(int j=0;a[i][j]!='\0';j++){
        sum+=a[i][j];
    }
    }
}


int main(){
    int n=2,m=3;
    char **p=(char **)a;
    f(p,n,m);
    printf("%d",sum);
    return 0;
}