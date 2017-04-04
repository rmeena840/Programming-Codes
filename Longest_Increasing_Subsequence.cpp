#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n){
	
	int sizeoflis[n];
	for(int i=0;i<n;i++)
		sizeoflis[i]=1;
		
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++)
			if(arr[i]>arr[j] && sizeoflis[i]<sizeoflis[j]+1)
				sizeoflis[i]=sizeoflis[j]+1;
	}
	
	int max=sizeoflis[0];
	for(int i=0;i<n;i++){
		if(max<sizeoflis[i])
			max=sizeoflis[i];
	}
	
	return max;
}

int main(void){
	int arr[5]={3,10,2,1,20};
	cout<<lis(arr,sizeof arr/sizeof arr[0]);
	return 0;
}
