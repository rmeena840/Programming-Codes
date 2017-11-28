#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}node;

int height(node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
 
/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(node* root)
{
    int h = height(root);
    for (int i=1; i<=h; i++)
        printGivenLevel(root, i);
}

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

int main(void){
	int a;
	cin>>a;
	node *root=NULL;
	while(a--){
		int n;
		cin>>n;
		root=insertnode(root,n);
	}	
	printLevelOrder(root);
	return 0;
}
