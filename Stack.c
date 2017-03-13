#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Nide *right;
}node;

typedef struct stack{
    node *info;
    struct stack *next;
}stack;

stack* push(node*root,stack*s){
    s=push(root,s);
    root=NULL;
    if(root==NULL){

    }
}

node* getnewnode(int x){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=x;
    return newnode;
}

node* insert(node* root, int x){
    if(root==NULL){
        root=getnewnode(x);
    }else if(x<=root->data){
    root->left=insert(root->left,x);
    }else{
    root->right=insert(root->right,x);
    }
    return root;
}

/*
void preorder(node *root){
    if(root!=NULL){
     printf("%d ",root->data);
     preorder(root->left);
     preorder(root->right);
    }
}

void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
*/

int main(void){
    node *root=NULL;
    stack *stack=NULL;
    printf("How many nodes you want in BST?\n");
    int a,b,c,d;
    scanf("%d",&a);
    for(b=0;b<a;b++){
        scanf("%d",&c);
        root=insert(root,c);
    }
    /*
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    */
    return 0;
}
