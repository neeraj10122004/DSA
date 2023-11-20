#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* temp = NULL;
void addnodeatend(int val){
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        temp=newnode;
        head=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void addnodeatbegin(int val){
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        temp=newnode;
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void addnodeatposition(int val,int pos){
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    struct node* temp;
    struct node* temp1;
    temp=head;
    int i=0;
    while(i<pos && temp!=NULL){
        temp1=temp;
        temp=temp->next;
        i++;
    }
    if(head==NULL){
        temp=newnode;
        head=newnode;
    }
    newnode->next=temp;
    temp1->next=newnode;
}
void delatend(){
    if(head==NULL){
        printf("empty");
    }
    else{
        struct node* t;
        struct node* s;
        t=head;
        while(t->next!=NULL){
            s=t;
            t=t->next;
        }
        s->next=NULL;
        free(t);
    }
}
void delatbegin(){
    if(head==NULL){
        printf("empty");
    }
    else if(head==temp){
        struct node* t;
        t=head;
        head=NULL;
        temp=NULL;
        free(t);
    }
    else{
        struct node* t;
        t=head;
        head=head->next;
        free(t);
    }
}
void deleteatpos(int pos){
    struct node* temp;
    struct node* temp1;
    temp=head;
    int i=0;
    while(i<pos && temp!=NULL){
        temp1=temp;
        temp=temp->next;
        i++;
    }
    temp1->next=temp->next;
}
int main(){
    int val,pos;
    struct node* t;
    while(1){
        int i;
        printf("1 to enter data at end\n2 to delete at end\n3 to enter data at begining\n4 to delete at begining\n5 to addatposition\n6 to delete at pos\n7 to display\n");
        scanf("%d",&i);
        switch(i){
            case 1 :
                printf("enter value\n");
                scanf("%d",&val);              
                addnodeatend(val);
                break;
            case 2 :
                delatend();
                break;
            case 3 :
                printf("enter value\n");
                scanf("%d",&val);              
                addnodeatbegin(val);
                break;
            case 4 :
                delatbegin();
                break;
            case 5 :
                printf("enter value\n");
                scanf("%d",&val);   
                printf("enter position\n");
                scanf("%d",&pos);          
                addnodeatposition(val,pos);
                break;
            case 6 :
                printf("enter pos\n");
                scanf("%d",&pos);              
                deleteatpos(pos);
                break;
            case 7 :
                t = head;
                printf("values: \n");
                while(t!=NULL){
                    printf("%d\n",t->data);
                    t=t->next;
                }
                break;
            
            default:
                printf("error");
                break;
        }
    }
    return 0;
}