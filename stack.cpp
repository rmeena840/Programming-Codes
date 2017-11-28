#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}node;

node* head=NULL;

void push(int n){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=n;
	if(head==NULL){
		head=newnode;
		newnode->next=NULL;
	}else{
		node* temp=head;
		newnode->next=temp;
		head=newnode;
	}
}

void pop(){
	node* temp=head;
	node* temp1=temp->next;
	head=temp1;
	cout<<temp->data;
}

int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		push(a);
	}
	for(int i=0;i<n;i++){
		pop();
	}
	return 0;
}
