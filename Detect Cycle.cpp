#include<bits/stdc++.h>
using namespace std;
vector< list< pair<int,int> > > v;
vector<int> visited;
vector<int> recstack;

int isCyclicUtil(int i){
	if(visited[i]==0){
		visited[i]=1;
		recstack[i]=1;
		list< pair<int,int> >::iterator itr=v[i].begin();
		while(itr!=v[i].end()){
			if(!visited[(*itr).first] && isCyclicUtil((*itr).first))
				return 1;
				else if(recstack[(*itr).first])
				return 1;
			itr++;
		}
		
	}
	recstack[i]=0;
	return 0;
}

int isCyclic(int n){
	for(int i=1;i<=n;i++){
		if(isCyclicUtil(i))
		return 1;
	}
	return 0;
}

int main(void){
	int n,e;
	cin>>n>>e;
	v.resize(n+1);
	visited.resize(n+1);
	recstack.resize(n+1);
	for(int i=1;i<=e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
	}
	for(int i=1;i<=n;i++){
		cout<<i<<"->";
		list< pair<int,int> >::iterator itr=v[i].begin();
		while(itr!=v[i].end()){
			cout<<(*itr).first<<" ";
			itr++;
		}
		cout<<endl;
	}
	if(isCyclic(n)){
		cout<<"Cyclic"<<endl;
	}else{
		cout<<"Not Cyclic"<<endl;
	}
	return 0;
}
