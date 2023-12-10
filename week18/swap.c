#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void push(struct node** head,int data){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(*head==NULL){
        new->next=new;
        *head=new;
    }
    else{
        struct node* temp=*head;
        while(temp->next!=*head){
            temp=temp->next;
        }
        temp->next=new;
        new->next=*head;
    }
}
void swap(struct node** head){
    struct node* temp=(*head)->next;
    struct node* a=temp->next;
    (*head)->next=a;
    temp->next=a->next;
    a->next=temp;
}
void disp(struct node* head){
    struct node* temp=head;
    while(temp->next!=head){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}
int main(){
    struct node* head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    disp(head);
    printf("\n");
    swap(&head);
    disp(head);
    return 0;
}