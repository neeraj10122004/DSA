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
void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node* root = create(1);
    struct node* n1 = create(2);
    struct node* n2 = create(3);
    struct node* n3 = create(4);
    struct node* n4 = create(5);
    struct node* n5 = create(6);
    root->left=n1;
    root->right=n2;
    n1->left=n3;
    n1->right=n4;
    n2->left=n5;
    postorder(root);
    return 0;
}