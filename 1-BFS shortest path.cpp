#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll bfs(vector<ll> G[],ll n,ll m){
	queue<ll> q;
	bool vis[n+1]={false};
	ll level[n+1]={0};
	q.push(1);
	level[1]=0;
	vis[1]=true;
	while(!q.empty()){
		ll v=q.front();
		q.pop();
		for(ll i=0;i<G[v].size();i++){
			if(vis[G[v][i]]==false){
				level[G[v][i]]=level[v]+1;
				vis[G[v][i]]=true;
				q.push(G[v][i]);
			}
		}
	}
	cout<<level[n]<<endl;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<ll> G[n+1];
		for(ll i=1;i<=m;i++){
			ll x,y;
			cin>>x>>y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		bfs(G,n,m);
	}
	return 0;
}
