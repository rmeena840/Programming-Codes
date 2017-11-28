#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *next;
}que;

que *front=NULL;
que *rear=NULL;

void insertnode(int n){
	que* newnode=(que*)malloc(sizeof(que));
	newnode->data=n;
	if(front==NULL){
		newnode->next=NULL;
		front=newnode;
		rear=newnode;
	}else{
		que* temp=(que*)malloc(sizeof(que));
		temp=rear;
		newnode->next=NULL;
		temp->next=newnode;
		rear=newnode;
	}
}

void printlist(){
	que* temp=(que*)malloc(sizeof(que));
	temp=front;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

void dequeue(){
	que* temp=(que*)malloc(sizeof(que));
	temp=front;
	temp=temp->next;
	front=temp;
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
	dequeue();
	cout<<endl;
	printlist();
	return 0;
}
