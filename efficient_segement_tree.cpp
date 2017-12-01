#include<bits/stdc++.h>
using namespace std;

#define ll ussigned long long int
#define N 100000

int n;
int tree[2*N];

void build(int arr[]){
	 // insert leaf nodes in tree
    for (int i=0; i<n; i++)    
        tree[n+i] = arr[i];
     
    // build the tree by calculating parents
    for (int i = n - 1; i > 0; --i)     
        tree[i] = tree[i<<1] + tree[i<<1 | 1]; 
}

void updateTreeNode(int p,int value){
	// set value at position p
    tree[p+n] = value;
    p = p+n;
     
    // move upward and update parents
    for (int i=p; i > 1; i >>= 1)
        tree[i>>1] = tree[i] + tree[i^1];
}

int query(int l,int r){
	 int res = 0;
     
    // loop to find the sum in the range
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l&1) 
            res += tree[l++];
     
        if (r&1) 
            res += tree[--r];
    }
     
    return res;
}

int main(void){
	int a[] = {-1,2,3};
    n = sizeof(a)/sizeof(a[0]);
    build(a);
    cout << query(1, 2)<<endl;
    
    // modify element at 2nd index
    updateTreeNode(2, 1);
    
    cout << query(1, 3)<<endl;
	return 0;
}
