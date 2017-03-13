#include<bits/stdc++.h>
using namespace std;

vector<int> visited;

bool isReachable(list< pair<int,int> > v[],int s,int d,int n){
	visited.resize(n+1);
	for(int i=1;i<=n;i++)
		visited[i]=0;
	queue<int> q;
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int k=q.front();
		q.pop();
		list< pair<int,int> >::iterator itr=v[k].begin();
		while(itr!=v[k].end()){
			if(visited[(*itr).first]==0){
				visited[(*itr).first]=1;
				q.push((*itr).first);	
			}			
			if((*itr).first==d)
				return true;
			itr++;
		}
	}
	return false;
}
int main(void){
	int n,e;
	cin>>n>>e;
	list< pair<int,int> > v[n+1];
	for(int i=1;i<=e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	int src,dest;
	cout<<"Source?:";
	cin>>src;
	cout<<"Destination?:";
	cin>>dest;
	if(isReachable(v,src,dest,n))
		cout<<"Connected";
		else
		cout<<"Disconnected";
	return 0;
}
