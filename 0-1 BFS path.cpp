#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void bfs(vector< pair<ll,ll> > G[],ll n){
	ll dis[n+1]={INT_MAX};
	deque<ll> q;
	q.push_back(1);
	dis[1]=0;
	while(!q.empty()){
		ll v=q.front();
		q.pop_front();
		for(ll i=0;i<G[v].size();i++){
			if(dis[G[v][i].first]>dis[v]+G[v][i].second){
				dis[G[v][i].first]=dis[v]+G[v][i].second;
				if(G[v][i].second==0){
					q.push_front(G[v][i].first);
				}else{
					q.push_back(G[v][i].first);
				}
			}
		}
	}
	for(ll i=1;i<=n;i++){
		cout<<dis[i]<<endl;
	}
}

int main(void){
	ll n,m;
	cin>>n>>m;
	vector< pair<ll,ll> > G[5];
	G[0].push_back(make_pair(1,1));
	G[1].push_back(make_pair(0,1));
	G[0].push_back(make_pair(2,1));
	G[2].push_back(make_pair(0,1));
	G[0].push_back(make_pair(3,0));
	G[3].push_back(make_pair(0,0));
	G[1].push_back(make_pair(4,0));
	G[4].push_back(make_pair(1,0));
	G[3].push_back(make_pair(4,0));
	G[4].push_back(make_pair(3,0));
	G[2].push_back(make_pair(3,0));
	G[3].push_back(make_pair(2,0));
	bfs(G,n);
	return 0;
}
