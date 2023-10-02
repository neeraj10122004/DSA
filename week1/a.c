//factorial of nuumber using recursion

#include <stdio.h>

int factorial(int x){
    if(x==0 || x==1){
        return 1;
    }
    else{
        return x*factorial(x-1);
    }
}
int main(){
    int a;
    printf("enter the number : ");
    scanf("%d",&a);
    printf("the factorial of the %d is %d",a,factorial(a));
    return 0;
}