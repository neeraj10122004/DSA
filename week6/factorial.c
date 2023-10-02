#include<stdio.h>
int size;
void push(int* a,int* top,int value){
    if(*top==size-1){
        printf("invalied\n");
    }
    else{
    *top+=1;
    a[*top]=value;
    }

}
int pop(int* a,int* top){
    if(*top==-1){
        printf("invalied\n");
        return 0;
    }
    else{
    int ret = a[*top];
    *top-=1;
    return ret;
    }
}

int main(){
    int top=-1;
    printf("enter the number\n");
    scanf("%d",&size);
    int value=1;
    int stack[size];
    for(int i=0;i<size;i++){
        push(stack,&top,i+1);
    }
    while(top>=0){
        value*=pop(stack,&top);
    }
    printf("\nfactorial : %d\n",value);
    return 0;
}