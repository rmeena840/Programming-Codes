#include<bits/stdc++.h>
using namespace std;

struct job{
	char id;
	int deadline;
	int profit;
};

bool sortprofit(job s1,job s2){
	return (s1.profit > s2.profit);
}

int jobsequencing(job arr[],int n){
	sort(arr,arr+n,sortprofit);
	int result[n];
	memset(result,-1,sizeof result);
	for(int i=0;i<n;i++){
		int k=arr[i].deadline;
		k=k-1;
		for(int j=k;j>=0;j--){
			if(result[j]==-1){
				result[j]=i;
				break;
			}
		}
	}
	int totalprofit;
	for(int i=0;i<n;i++){
		if(result[i]!=-1){
			cout<<arr[result[i]].id<<" ";
			totalprofit+=arr[result[i]].profit;
		}
	}
	return totalprofit;
}

int main(void){
	job arr[]={{'A',2,100},{'B',1,19},{'C',2,27},{'D',1,25},{'E',3,15}};
	cout<<"\nTotal profit: "<<jobsequencing(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
