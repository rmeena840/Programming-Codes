#include<bits/stdc++.h>
using namespace std;

struct knap{
	int profit;
	int weight;
};

bool cmp(knap s1,knap s2){
	return s1.profit/s1.weight>s2.profit/s2.weight;
}

float knapsack(knap arr[],int total){
	float curprofit=0;
	int totalweight=0;
	sort(arr,arr+5,cmp);
	for(int i=0;i<5;i++){
		if(arr[i].weight+totalweight<=total){
				curprofit+=arr[i].profit;
				totalweight+=arr[i].weight;
		}else{	
				int remain=total-totalweight;
				curprofit+=arr[i].profit*((float)remain/arr[i].weight);
				break;
		}
	}
	return curprofit;
}

int main(void){
	knap arr[]={{25,5},{28,4},{30,3},{15,4},{20,5}};
	cout<<"Maximum Profit: "<<knapsack(arr,15)<<endl;
	return 0;
}
