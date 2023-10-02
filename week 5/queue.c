#include<stdio.h>
int size;
void enqueue(int * a,int* front,int* rear,int value){
    if(*rear==size-1){
        printf("invalied\n");
    }
    else if(*front == -1){
        *front=0;
        *rear=0;
        a[*rear]=value;
    }
    else{
        *rear+=1;
        a[*rear]=value;
    }
}
void dequeue(int * a,int* front,int* rear){
    int value;
    if(*front==-1){
        printf("invalied\n");
    }
    else if(*front==*rear){
        *front=-1;
        *rear=-1;
    }
    else{
        *front+=1;
    }
}
int peek(int* a,int* front){
    if(*front!=-1){
    return a[*front];
    }
}
void display(int* a,int* rear,int* front){
    if(*front<=*rear && *front!=-1 && *rear!=-1){
    printf("values : \n");
    for(int i=*front;i<=*rear;i++){
        printf("%d\n",a[i]);
    }}

}
int main(){
    int front=-1;
    int rear=-1;
    printf("enter size\n");
    scanf("%d",&size);
    int value;
    int queue[size];
    while(1){
        int x;
        printf("1 to enqueue\n2 to dequeue\n3 to dispiay\n4 to peek\n");
        scanf("%d",&x);
        switch (x) {
            case 1 :
                scanf("%d",&value);
                enqueue(queue,&front,&rear,value);
                break;
            case 2 :
                dequeue(queue,&front,&rear);
                break;
            case 3 :
                display(queue,&rear,&front);
                break;
            case 4 :
                printf("%d\n",peek(queue,&front));
                break;
            default :
                printf("invalied\n");
        }
    }
    return 0;
}