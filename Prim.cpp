#include<bits/stdc++.h>
using namespace std;

int prim(list< pair<int,int> > v[],int n,int s){
	priority_queue< pair<int,int>, vector< pair<int,int> >,greater< pair<int,int> > > Q;
	
	vector<int> key(n+1,INT_MAX);
	vector<int> parent(n+1,-1);
	vector<bool> MST(n+1,false);
	
	Q.push(make_pair(0,s));
	key[s]=0;
	
	while(!Q.empty()){
		int k=Q.top().second;
		Q.pop();
		MST[k]=true;
		
		list< pair<int,int> >::iterator itr=v[k].begin();
		while(itr!=v[k].end()){
			if(MST[(*itr).first]==false && key[(*itr).first]>((*itr).second)){
				parent[(*itr).first]=k;
				key[(*itr).first]=(*itr).second;
				Q.push(make_pair((*itr).second,(*itr).first));
			}
			itr++;
		}
	}
	int total=0;
	for(int i=1;i<=n;i++)
			total+=key[i];
			
		return total;
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
	cout<<prim(v,n,1);
	return 0;
}
