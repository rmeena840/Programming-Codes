#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}node;

typedef struct Stack{
	node* item;
	struct Stack* next;
}stack;

node* getnewnode(int x){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node* createtree(node* root,int x){
	if(root==NULL){
		root=getnewnode(x);
	}else if(x<=root->data){
		root->left=createtree(root->left,x);
	}else{
		root->right=createtree(root->right,x);
	}
	return root;
}

stack* stackhead=NULL;

void push(node*root){
	stack* newnode=(stack*)malloc(sizeof(stack));
	newnode->item=root;
	newnode->next=stackhead;
	stackhead=newnode;
}

node* top(){
	return stackhead->item;
}

void pop(){
	stackhead=stackhead->next;
}

void preorder(node*root){
	push(NULL);
	node* ptr=root;
	while(ptr!=NULL){
		printf("%d",ptr->data);
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
	int a,b,c,d,e;
	scanf("%d",&a);
	node* root=NULL;
	for(b=0;b<a;b++){
		scanf("%d",&c);
		root=createtree(root,c);
	}
	preorder(root);
	return 0;
}
