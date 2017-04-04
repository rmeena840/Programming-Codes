#include<bits/stdc++.h>
using namespace std;

bool G[4][4]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};

bool isSafe(int v,int color[],int c){
	for(int i=0;i<v;i++)
			if(G[v][i] && c==color[i])
				return false;
		return true;
}

bool isPossible(int m,int color[],int v){
	if(v==4)
		return true;
	for(int i=1;i<=m;i++){
		if(isSafe(v,color,i)){
			color[v]=i;
			if(isPossible(m,color,v+1))
				return true;
			color[v]=0;
		}
	}
	return false;
}

void printsolution(int color[]){
	for(int i=0;i<4;i++){
		cout<<color[i]<<" ";
	}
}

bool coloring(int m){
	int color[4];
	memset(color,0,sizeof color);
	if(isPossible(m,color,0)==false){
		cout<<"No Solution Exists.\n";
		return false;
	}
	
	printsolution(color);
	return true;
}

int main(void){
	int m=3;
	coloring(m);
	return 0;
}
