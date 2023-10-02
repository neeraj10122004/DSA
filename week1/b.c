//tower of hanoi problem

#include <stdio.h>
void toh(int n,char a,char b,char c){
    if(n==1){
        printf("%c -> %c\n",a,c);
    }
    else{
    toh(n-1,a,c,b);
    toh(1,a,b,c);
    toh(n-1,b,a,c);
    }
}

int main(){
    int x;
    scanf("%d",&x);
    toh(x,'A','B','C');
    return 0;
}