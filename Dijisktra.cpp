#include<bits/stdc++.h>
using namespace std;

const int MAX =1e5+1;
vector< pair<int,int> > G[MAX]; 
int dis[MAX];

void initialize(){
	for(int i=0;i<MAX;i++){
		dis[i]=INT_MAX;
	}
}

void dijisktra(int s){
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > Q;
	dis[s]=0;
	Q.push({0,s});
	while(!Q.empty()){
		pair<int,int> p=Q.top();
		Q.pop();
		int x=p.second;
		for(int i=0;i<G[x].size();i++){
			if(dis[x]!=INT_MAX && dis[G[x][i].second]>dis[x]+G[x][i].first){
				dis[G[x][i].second]=dis[x]+G[x][i].first;
				Q.push(G[x][i]);
			}
		}
	}
}

int main(void){
	int n,e;
	cin>>n>>e;
	initialize();
	for(int i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back({w,y});
		G[y].push_back({w,x});
	}
	dijisktra(1);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<endl;
	}
	return 0;
}
