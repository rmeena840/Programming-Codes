#include<bits/stdc++.h>
using namespace std;

bool G[5][5]={{0,1,0,1,0},{1,0,1,1,1},{0,1,0,0,1},{1,1,0,0,1},{0,1,1,1,0}};

bool isSafe(int v,int path[],int pos){
	if(G[path[pos-1]][v]==0)
		return false;
	for(int i=0;i<pos;i++)
		if(path[i]==v)
			return false;
	return true;
}

bool isPossible(int path[],int pos){
	if(pos==5){
		if(G[path[pos-1]][path[0]]==1)
			return true;
			else
			return false;
	}
	for(int i=1;i<5;i++){
		if(isSafe(i,path,pos)){
			path[pos]=i;
			if(isPossible(path,pos+1))
				return true;
				path[pos]=-1;
		}
	}
	return false;
}

void printsol(int path[]){
	for(int i=0;i<5;i++){
		cout<<path[i]<<" ";
	}
	cout<<path[0]<<endl;
}

bool hamCycle(){
	int path[5];
	memset(path,-1,sizeof path);
	path[0]=0;
	if(isPossible(path,1)==false){
		cout<<"No Solution\n";
		return false;
	}
	printsol(path);
	return true;
}

int main(void){
	hamCycle();
	return 0;
}
