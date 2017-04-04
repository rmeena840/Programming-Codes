#include<bits/stdc++.h>
using namespace std;
#define size 3

int id[size];
pair< int,pair<int,int> > G[size];

void initialize(){
	for(int i=1;i<=4;i++){
		id[i]=i;
	}
}

int root(int x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(int x,int y){
	int p=root(x);
	int q=root(y);
	id[p]=id[q];
}

int kruskal(){
	int x,y,cost,minimumcost=0;
	for(int i=1;i<=size;i++){
		x=G[i].second.first;
		y=G[i].second.second;
		cost=G[i].first;
		if(root(x)!=root(y)){
			minimumcost+=cost;
			union1(x,y);
		}
	}
	return minimumcost;
}

int main(void){
	initialize();
	for(int i=1;i<=size;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[i]=make_pair(c,make_pair(a,b));
	}
	sort(G,G+size);
	cout<<kruskal()<<endl;
	return 0;
}
