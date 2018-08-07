#include<bits/stdc++.h>
using namespace std;

const int MAX=1e4+5;
vector< pair<int,int> > G[MAX];
int dist[MAX];

void dijkstra(int s){
	priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > pq;
	for(int i=0;i<MAX;i++)
		dist[i]=INT_MAX;
	dist[s]=0;
	pq.push(make_pair(s,0));
	
	while(!pq.empty()){
		pair<int,int> minvertex=pq.top();
		int u=minvertex.first;
		pq.pop();
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].first;
			int w=G[u][i].second;
			if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				pq.push(make_pair(v,dist[v]));
			}
		}
	}
	
}

int main(void){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back(make_pair(y,w));
		G[y].push_back(make_pair(x,w));
	}
	dijkstra(1);
	for(int i=0;i<n;i++){
		cout<<dist[i]<<endl;
	}
	return 0;
}
