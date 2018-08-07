#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<int> v[5];
bool vis[5]={false};
int level[5]={0};

void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s]=true;
	while(!q.empty()){
		int a=q.front();
		q.pop();
		for(int i=0;i<v[a].size();i++){
			if(vis[v[a][i]]==false){
				level[v[a][i]]=level[a]+1;
				q.push(v[a][i]);
				vis[v[a][i]]=true;
			}
		}
	}
	
}

int main(void){
	ios_base::sync_with_stdio(false);
	int x,y;
	for(int i=0;i<4;i++){
		cin>>x>>y;
		v[x].push_back(y);
	}
	bfs(0);
	for(int i=0;i<=4;i++){
		cout<<level[i]<<endl;
	}
	return 0;
}
