#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}node;

typedef struct Stack{
    node *info;
    struct Stack *next;
}stacknew;

stacknew *stackhead=NULL;


void push(node* root){
    stacknew *newinsert=(stacknew*)malloc(sizeof(stacknew));
    if(root==NULL){
    newinsert->info=root;
    newinsert->next=stackhead;
    stackhead=newinsert;
    }else{
        newinsert->info=root;
        newinsert->next=stackhead;
        stackhead=newinsert;
    }
}

void pop(){
    stackhead=stackhead->next;
}

node* getnewnode(int x){
    node* newnode=new node;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->data=x;
    return newnode;
}

node* top(){
    return stackhead->info;
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

void preorder(node *root){
    node *ptr=root;
    push(NULL);
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        if(ptr->right!=NULL){
            push(ptr->right);
        }
        if(ptr->left!=NULL){
            ptr=ptr->left;
        }else{
            ptr=top();
            pop();
        }
    }
}

int main(void){
    node *root=NULL;
    cout<<"How many elemets you want in a tree?\n";
    int a,b,c,d;
    cin>>a;
    for(b=0;b<a;b++){
        cin>>c;
        root=insert(root,c);
    }
    preorder(root);

return 0;
}
