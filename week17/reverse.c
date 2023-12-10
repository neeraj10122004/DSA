#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void push(struct node** head,int data){
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->data=data;
    new->next=*head;
    *head=new;
}

void disp(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void reverse(struct node** head){
    struct node* prev=NULL;
    struct node* current=*head;
    struct node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *head=prev;
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
    reverse(&head);
    disp(head);
    return 0;
}