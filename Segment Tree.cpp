#include<bits/stdc++.h>
using namespace std;

int getmid(int ss,int se){
	return ss+(se-ss)/2;
}

int constructSTutil(int arr[],int ss,int se,int *st,int si){
	if(ss==se){
		st[si]=arr[ss];
		return arr[ss];
	}
	int mid=getmid(ss,se);
	st[si]=constructSTutil(arr,ss,mid,st,2*si+1)+constructSTutil(arr,mid+1,se,st,2*si+2);
	return st[si];
}

int* constructST(int arr[],int n){
	int x=(int)(ceil(log2(n)));
	int max_size=2*(int)pow(2,x)-1;
	int *st=new int[max_size];
	constructSTutil(arr,0,n-1,st,0);
	return st;	
}

int getsumutil(int *st,int ss,int se,int qs,int qe,int si){
	if(qs<=ss && qe>=se)
		return st[si];
	if(se<qs || ss>qe)
		return 0;
	int mid=getmid(ss,se);
	return getsumutil(st,ss,mid,qs,qe,2*si+1)+getsumutil(st,mid+1,se,qs,qe,2*si+2);
}

int getsum(int *st,int n,int qs,int qe){
	if(qs<0 || qe>n-1 || qs>qe){
		return -1;
	}
	getsumutil(st,0,n-1,qs,qe,0);
}

void updatevalueutil(int *st,int ss,int se,int i,int diff,int si){
	if(i<ss || i>se)
		return;
	st[si]=st[si]+diff;
	if(se!=ss){
		int mid=getmid(ss,se);
		updatevalueutil(st,ss,mid,i,diff,2*si+1);
		updatevalueutil(st,mid+1,se,i,diff,2*si+2);
	}
}

void updatevalue(int arr[],int *st,int n,int i,int new_val){
	if(i<0 || i>n-1){
		return;
	}
	int diff=new_val-arr[i];
	arr[i]=new_val;
	updatevalueutil(st,0,n-1,i,diff,0);
}

int main(void){
	int arr[]={1,3,5,7,9,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *st=constructST(arr,n);
	cout<<"Sum in given range "<<getsum(st,n,1,3)<<endl;
	updatevalue(arr,st,n,1,10);
	cout<<"Sum in given range "<<getsum(st,n,1,3)<<endl;
	return 0;
}
