#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

int partition(int arr[],int l,int r){
	int x=arr[r];
	int count=l;
	for(int i=l;i<r;i++){
		if(arr[i]<=x){
			swap(&arr[count],&arr[i]);
			count++;
		}
	}
	swap(&arr[count],&arr[r]);
	return count;
}

int small(int arr[],int l,int r,int k){
	if(k>0 && k<=r-l+1){
		int pos=partition(arr,l,r);
		if(pos-l==k-1)
			return arr[pos];
		if(pos-l>k-1)
			return small(arr,l,pos-1,k);
		return small(arr,pos+1,r,k-pos+l-1);
	}
	return INT_MAX;
}


int main(void){
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int n=sizeof arr/sizeof arr[0];
	cout<<small(arr,0,n-1,3);
	return 0;
}
