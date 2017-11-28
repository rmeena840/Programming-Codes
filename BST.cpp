#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}node;

node* getnewnode(int n){
	node* newnode=(node*)malloc(sizeof(node));
	newnode->data=n;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node* insertnode(node* root,int n){
	if(root==NULL) return getnewnode(n);
	if(n<root->data)
		root->left=insertnode(root->left,n);
	else if(n>root->data)
		root->right=insertnode(root->right,n);
	
	return root;
}

void inorder(node* root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void preorder(node* root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

node * minValueNode(node* root)
{
    node* current=root;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

node* deletenode(node* root,int key){
	// base case
    if (root == NULL) return root;
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deletenode(root->left, key);
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deletenode(root->right, key);
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deletenode(root->right, temp->data);
    }
    return root;
}

int height(node* root){
	if(root==NULL)
		return 0;
	else return max(height(root->left),height(root->right))+1;
}

int main(void){
	int a;
	cin>>a;
	node *root=NULL;
	while(a--){
		int n;
		cin>>n;
		root=insertnode(root,n);
	}	
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	preorder(root);cout<<endl;
	cout<<"After Deleting:"<<endl;
	deletenode(root,3);
	preorder(root);
	cout<<"\nHeight: "<<height(root)<<endl;
	return 0;
}
