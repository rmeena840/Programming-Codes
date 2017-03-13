#include<bits/stdc++.h>
using namespace std;

vector< list< int > > v;
vector<int> visited;
void dfs(int s){
	stack<int> stock;
	stock.push(s);
	visited[s]=1;
	while(!stock.empty()){
		int k=stock.top();
		stock.pop();
		cout<<k;
		list<int>::iterator itr=v[k].begin();
		while(itr!=v[k].end()){
			if(visited[(*itr)]==0){
			stock.push((*itr));
			visited[(*itr)]=1;
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
		list< int >::iterator itr=v[i].begin();
		cout<<i<<"::";
		while(itr!=v[i].end()){
			cout<<(*itr)<<" ";
			itr++;
		}
		cout<<endl;
	}
	dfs(1);	
	return 0;
}
