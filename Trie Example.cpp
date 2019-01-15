#include<bits/stdc++.h>
using namespace std;

#define SIZE 26

struct Node{
	struct Node* children[SIZE];
	bool isEndofword;
};

struct Node* getNode(){
	struct Node* newnode=new Node;
	newnode->isEndofword=false;
	for(int i=0;i<SIZE;i++)
		newnode->children[i]=NULL;
	return newnode;
}

void insert(struct Node* root,string key){
	struct Node* newnode=root;
	for(int i=0;i<key.length();i++){
		int index=key[i]-'a';
		if(!newnode->children[index])
			newnode->children[index]=getNode();
		newnode=newnode->children[index];
	}
	newnode->isEndofword=true;
}

bool search(struct Node* root,string key){
	struct Node* newnode=root;
	for(int i=0;i<key.length();i++){
		int index=key[i]-'a';
		if(!newnode->children[index])
			return false;
		newnode=newnode->children[index];
	}
	return newnode->isEndofword && newnode!=NULL;
}

int countChildren(struct Node* root,int *index){
	int count=0;
	struct Node* newnode=root;
	for(int i=0;i<SIZE;i++){
		if(newnode->children[i]!=NULL){
			count++;
			*index=i;
		}
	}
	return count;
}

string computeprefix(struct Node* root){
	struct Node* newnode=root;
	int index;
	string prefix;
	while(countChildren(newnode,&index)==1 && newnode->isEndofword==false){
		newnode=newnode->children[index];
		prefix+='a'+index;
	}
	return prefix;
}

int main(void){
	string keys[] = {"tpple","tpe","tpp"}; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    struct Node *root = getNode();
    
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]);
  
  	cout<<computeprefix(root)<<endl;
  
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" : 
                         cout << "No\n";
	
	return 0;
}
