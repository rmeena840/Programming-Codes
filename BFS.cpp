#include<bits/stdc++.h>
using namespace std;

vector< list<int> > v;
vector<int> visited;

void bfs(int s){
	queue<int> stock;
	stock.push(s);
	visited[s]=1;
	while(!stock.empty()){
		int k=stock.front();
		cout<<k;
		stock.pop();
		list<int>::iterator itr=v[k].begin();
		while(itr!=v[k].end()){
			if(visited[(*itr)]==0){
				visited[(*itr)]=1;
				stock.push(*itr);
			}
			itr++;
		}
	}
}

int main(void){
	int n,e;
	cin>>n>>e;
	v.resize(n+1);
	visited.resize(n+1);
	for(int i=1;i<=e;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		cout<<i<<"->";
		list<int>::iterator itr=v[i].begin();
		while(itr!=v[i].end()){
			cout<<(*itr)<<"";
			itr++;
		}
		cout<<endl;
	}
	bfs(3);
	return 0;
}
