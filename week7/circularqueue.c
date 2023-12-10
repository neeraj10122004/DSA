#include<stdio.h>
int size;
void enqueue(int* queue,int* front,int* rear,int value){
    if(*front-*rear==1 || (*front==0 && *rear==size-1)){
        printf("error\n");
        return ;
    }
    else if(*front==-1 ){
        *front=0;
        *rear=0;
        queue[*rear]=value;
    }
    else{
        *rear=(*rear+1)%size;
        queue[*rear]=value;
    }
}
int dequeue(int* queue,int* front,int * rear){
    int ret;
    if(*front==-1){
        printf("error\n");
        return 404;
    }
    else if(*front==*rear){
        ret=queue[*front];
        *front = -1;
        *rear = -1;
    }
    else{                              
        ret = queue[*front];
        *front=(*front+1)%size;
    }
    return ret;
}
void display(int* queue,int* front,int * rear){
    printf("values : \n");
    for(int i=*front;i<=*rear;i++){
        printf("%d\n",queue[i]);
    }
}
int main(){
    printf("enter the size of queue\n");
    scanf("%d",&size);
    int queue[size];
    int front=-1;
    int rear=-1;
    while(1>0){
        int a,value;
        scanf("%d",&a);
        switch (a){
            case 1 :
                printf("enter the value \n");
                scanf("%d",&value);
                enqueue(queue,&front,&rear,value);
                break;
            case 2 :
                printf("%d\n",dequeue(queue,&front,&rear));
                break;
            case 3 :
                display(queue,&front,&rear);
                break;
            default :
                printf("error \n");
        }
    }
    return 0;
}