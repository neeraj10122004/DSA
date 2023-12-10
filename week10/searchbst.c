#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* left;
    int data;
    struct node* right;
};
struct node* create(int data){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* search(struct node* root,int data){
    while(root!=NULL){
        if(data<root->data){
            root=root->left;
        }
        else if(data>root->data){
            root=root->right;
        }
        else if(data==root->data){
            return root;
            break;
        }
    }
    return NULL;
}
int main(){
    struct node* root = create(45);
    struct node* n1 = create(15);
    struct node* n2 = create(79);
    struct node* n3 = create(10);
    struct node* n4 = create(55);
    struct node* n5 = create(90);
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n2->right=n5;
    n2->left=n4;
    int i;
    scanf("%d",&i);
    if(search(root,i)==NULL){
        printf("%d not present in tree\n",i);
    }
    else{
        printf("%d present in tree\n",i);
    }
    return 0;
}