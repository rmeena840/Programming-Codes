#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector< pair<ll,ll> > G[5];
int dis[5]={INT_MAX};

void intialize(){
	for(int i=0;i<5;i++){
		dis[i]=INT_MAX;
	}
}

void bfs01(int s){
	deque<int> Q;
	Q.push_back(s);
	dis[s]=0;
	while(!Q.empty()){
		int x=Q.front();
		Q.pop_front();
		for(int i=0;i<G[x].size();i++){
			if(dis[G[x][i].first]>dis[x]+G[x][i].second){
				dis[G[x][i].first]=dis[x]+G[x][i].second;
				if(G[x][i].second==0)
					Q.push_front(G[x][i].first);
				else
					Q.push_back(G[x][i].first);
			}
		}
	}
}

int main(void){
	intialize();
	for(int i=0;i<4;i++){
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back(make_pair(y,w));
	}
	bfs01(0);
	for(int i=0;i<5;i++){
		cout<<dis[i]<<endl;
	}
	return 0;
}