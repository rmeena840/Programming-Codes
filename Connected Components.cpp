#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> G[6];
bool vis[10];

void dfs(ll s){
	stack<ll> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
		int x=q.top();
		q.pop();
		for(int i=0;i<G[x].size();i++){
			if(vis[G[x][i]]==false){
				q.push(G[x][i]);
				vis[G[x][i]]=true;
			}
		}
	}
}

int main(void){
	ll x,y;
	for(int i=0;i<4;i++){	
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int count=0;
	for(int i=0;i<5;i++){
		if(vis[i]==false){
			dfs(i);
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}