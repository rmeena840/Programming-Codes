#include<bits/stdc++.h>
using namespace std;

void pass(int **arr){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cout<<arr[i][j];
}

int main(void){
	int **arr;
	arr=new int*[5];	
	for(int i=0;i<5;i++){
		arr[i]=new int[5];
	}
		for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>arr[i][j];
	pass(arr);
	return 0;
}
