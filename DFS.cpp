#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<bool> vis;

void dfs(vector<ll> G[],ll n){
	stack<ll> s;
	s.push(n);
	while(!s.empty()){
		ll v=s.top();
		s.pop();
		for(ll i=0;i<G[v].size();i++){
			if(vis[G[v][i]]==false){
				vis[G[v][i]]=true;
				s.push(G[v][i]);
			}
		}
	}
}

int main(void){
	ll n,m;
	cin>>n>>m;
	vector<ll> G[n+1];
	vis.resize(n+1,false);
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ll cm=0;
	for(ll i=1;i<=n;i++){
		if(vis[i]==false){
				dfs(G,i);
				cm++;
		}
	}
	cout<<"Connected Components: "<<cm<<endl;
	return 0;
}
