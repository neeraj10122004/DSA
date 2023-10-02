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
int peak(int* a,int* top){
    if(*top==-1){
        return 0;
    }
    return a[*top];
}
void display(int* a,int* top){
    if(*top==-1){
        printf("enter elements\n");
    }
    else{
    printf("values : \n");
    for(int i=*top;i>=0;i--){
        printf("%d\n",a[i]);
    }}
}
int main(){
    int top=-1;
    printf("enter size\n");
    scanf("%d",&size);
    int value;
    int stack[size];
    while(1){
        int x;
        printf("1 to push\n2 to pop\n3 to peek\n4 to display\n");
        scanf("%d",&x);
        switch (x) {
            case 1 :
                scanf("%d",&value);
                push(stack,&top,value);
                break;
            case 2 :
                printf("%d\n",pop(stack,&top));
                break;
            case 3 :
                printf("%d\n",peak(stack,&top));
                break;
            case 4 :
                display(stack,&top);
                break;
            default :
                printf("invalied\n");
        }
    }
    return 0;
}