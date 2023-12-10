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
void insert(struct node* root,struct node* new){
    if(root!=NULL){
        if(new->data<root->data && root->left==NULL){
            root->left=new;
            return;
        }
        else if(new->data>root->data && root->right==NULL){
            root->right=new;
            return;
        }
        else if (new->data<root->data){
            insert(root->left,new);
        }
        else if(new->data>root->data){
            insert(root->right,new);
        }
    }
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    struct node* root = create(45);
    struct node* n1 = create(15);
    struct node* n2 = create(79);
    struct node* n3 = create(10);
    struct node* n4 = create(55);
    struct node* n5 = create(90);
    inorder(root);
    insert(root,n1);
    insert(root,n2);
    insert(root,n3);
    insert(root,n4);
    printf("\n");
    inorder(root);
    insert(root,n5);
    printf("\n");
    inorder(root);
    return 0;
}