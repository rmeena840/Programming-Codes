#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const ll MAX=1e4+5;
bool vis[MAX]={false};
typedef pair<ll,ll> PII;
vector< PII > G[MAX];

ll prim(ll x){
	priority_queue<PII,vector<PII>,greater<PII> > Q;
	PII p;
	Q.push(make_pair(0,x));
	ll mincost=0;
	while(!Q.empty()){
		p=Q.top();
		Q.pop();
		x=p.second;
		if(vis[x]==true)
			continue;
		mincost+=p.first;
		vis[x]=true;
		for(ll i=0;i<G[x].size();i++){
			ll y=G[x][i].second;
			if(vis[y]==false)
				Q.push(G[x][i]);
		}
	}
	return mincost;
}

int main(void){
	ll t,nodes,edges;

		cin>>nodes>>edges;
		for(ll i=1;i<=edges;i++){
			ll x,y,wt=1;
			cin>>x>>y;
			G[x].push_back(make_pair(wt,y));
			G[y].push_back(make_pair(wt,x));
		}
		cout<<prim(1)<<endl;
		for(ll i=0;i<MAX;i++){
			G[i].clear();
			vis[i]=false;
		}
	
	return 0;
}
