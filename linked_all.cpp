#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *head=NULL;

void insertnode(int n){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=n;	
	if(head==NULL){
		newnode->next=NULL;
		head=newnode;
	}else{
		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
	}
}

void printlist(){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void deletenode(int n){
	if(n==1){
		node* temp1=head;
		node* temp2=NULL;
		temp2=temp1->next;
		head=temp2;
	}else{
		node* temp1=head;
		node* temp2=NULL;
		for(int i=1;i<n;i++){
			temp2=temp1;
			temp1=temp1->next;
		}
		temp1=temp1->next;
		temp2->next=temp1;
	}
}

void reverse(){
	node* prev=NULL;
	node* next=NULL;
	node* current=head;
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}

int main(void){
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		int n;
		cin>>n;
		insertnode(n);
	}
	printlist();
	deletenode(3);cout<<endl;
	printlist();
	reverse();cout<<endl;
	printlist();
	return 0;
}
