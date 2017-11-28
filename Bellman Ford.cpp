#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > distances;

int bellman(list< pair<int,int> > G[],int n,int start){
	distances.resize(n+1);
	for(int i=1;i<=n;i++){
		distances[i].first=INT_MAX;
		distances[i].second=-1;
	}
	distances[start].first=0;
	distances[start].second=-1;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n;j++){
			list< pair<int,int> >::iterator itr=G[j].begin();
			while(itr!=G[j].end()){
				if(distances[j].first==INT_MAX){
					itr++;
					continue;
				}
				if((*itr).second+distances[j].first<distances[(*itr).first].first){
					distances[(*itr).first].first=(*itr).second+distances[j].first;
					distances[(*itr).first].second=j;
				}
				itr++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		list< pair<int,int> >::iterator itr=G[i].begin();
			while(itr!=G[i].end()){
				if((*itr).second+distances[i].first<distances[(*itr).first].first){
					return i;
				}
				itr++;
			}
		}
	return -1;
}


int main(void){
	int n,e;
	cin>>n>>e;
	list< pair<int,int> > G[n+1];
	for(int i=1;i<=e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back(make_pair(b,c));
	}
	int k=bellman(G,n,1);
	if(k==-1){
		for(int i=1;i<=n;i++){
			cout<<distances[i].first<<" "<<endl;
		}
	}else{
		cout<<"negative cycle\n";
	}
	return 0;
}
