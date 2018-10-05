#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define SIZE 26

struct Node{
	struct Node *children[SIZE];
	bool isEndOfWord;
};

struct Node* getNode(){
	struct Node *newNode=new Node;
	newNode->isEndOfWord=false;
	for(int i=0;i<SIZE;i++){
		newNode->children[i]=NULL;
	}
	return newNode;
}

void insert(struct Node* root,string key){
	struct Node *newNode=root;
	for(int i=0;i<key.length();i++){
		int index=key[i]-'a';
		if(!newNode->children[index])
			newNode->children[index]=getNode();
		newNode=newNode->children[index];
	}
	newNode->isEndOfWord=true;
}

bool search(struct Node* root,string key){
	struct Node *newNode=root;
	for(int i=0;i<key.length();i++){
		int index=key[i]-'a';
		if(!newNode->children[index])
			return false;
		newNode=newNode->children[index];
	}
	return newNode!=NULL && newNode->isEndOfWord;
}

int main(void){
	string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
    struct Node *root = getNode();
    
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]);
  
    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n";
    search(root, "these")? cout << "Yes\n" : 
                         cout << "No\n";
	return 0;
}
