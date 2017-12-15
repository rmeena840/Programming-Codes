#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int n,int W){
	int K[n+1][W+1];
	
	for(int i=0;i<=n;i++){
		for(int w=0;w<=W;w++){
			if(i==0 || w==0)
				K[i][w]=0;
			else if(wt[i-1]<=W){
				K[i][w]=max(K[i-1][w],val[i-1]+K[i-1][w-wt[i-1]]);
			}else{
				K[i][w]=K[i-1][w];
			}
		}
	}
	return K[n][W];
}

int main(void){
	
	std::ios::sync_with_stdio(false);
	
	int val[3]={60,100,120};
	int wt[3]={10,20,30};
	cout<<knapsack(val,wt,3,50);
	return 0;
}
