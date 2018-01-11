#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int MAX=1e4+5;
bool vis[MAX]={false};
vector<ll> G[MAX];

stack<ll> s;

void topological_sort(ll x){
	vis[x]=true;
	for(ll i=0;i<G[x].size();i++){
		if(vis[G[x][i]]==false){
			topological_sort(G[x][i]);
		}
	}
	s.push(x);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,m,x,y;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		cin>>x>>y;
		G[x].push_back(y);
	}
	for(ll i=1;i<=n;i++)
		if(vis[i]==false)
		topological_sort(i);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
