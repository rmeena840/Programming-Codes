#include<stdio.h>
#include<stdlib.h>

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
    node* newnode=(node*)malloc(sizeof(node));
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

void inorder(node * root){
node*    ptr=root;
    push(NULL);
  x:
    while(ptr!=NULL){
        push(ptr);
        ptr=ptr->left;
    }
    ptr=top();
    pop();
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        if(ptr->right!=NULL){
            ptr=ptr->right;
            goto x;
        }
        ptr=top();
        pop();
    }
}

int height(node * root){
 if(root!=NULL){
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight) return lheight+1;else return rheight+1;
    }
}

void level(node* root){
    int i;
    for(i=1;i<=height(root);i++)
        printlevel(root,i);
}

void printlevel(node* root,int level){
    if(root!=NULL){
        if(level==1)
            printf("%d ",root->data);
        else if(level>1){
            printlevel(root->left,level-1);
            printlevel(root->right,level-1);
        }
    }
}

void find(node* root,int x){
    node *ptr=NULL;
    if(root==NULL){
        printf("\There is no element\n");
    }else if(x==root->data){
        printf("\nFound it\n");
    }else if(x<root->data){
        ptr=root->left;
    }else{
        ptr=root->right;
    }
    while(ptr!=NULL){
        if(x==ptr->data){
            printf("\nFound it\n");
            ptr=NULL;}
        else if(x<ptr->data){
            ptr=ptr->left;
        }else{
            ptr=ptr->right;
        }

    }
}

int main(void){
    node *root=NULL;
    printf("How many elemets you want in a tree?\n");
    int a,b,c;
    scanf("%d",&a);
    for(b=0;b<a;b++){
        scanf("%d",&c);
        root=insert(root,c);
    }
    inorder(root);
    printf("\n Height of tree is: %d",height(root));
    printf("\n");
    level(root);
    find(root,5);
return 0;
}
