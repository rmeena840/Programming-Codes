#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > shortestdistance;

int bellmanford(list< pair<int,int> > v[],int n,int e,int start){
	shortestdistance.resize(n+1);
	for(int i=1;i<=n;i++){
		shortestdistance[i].first=INT_MAX;
		shortestdistance[i].second=-1;
	}

	shortestdistance[start].first=0;
	shortestdistance[start].second=0;
	
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n;j++){
			
			list< pair<int,int> >::iterator itr=v[j].begin();
			
			while(itr!=v[j].end()){
				if(shortestdistance[j].first!=INT_MAX && shortestdistance[j].first+(*itr).second<shortestdistance[(*itr).first].first){
					shortestdistance[(*itr).first].first=shortestdistance[j].first+(*itr).second;
					shortestdistance[(*itr).first].second=j;
				}
				itr++;
			}
			
		}
	}
	
	for(int i=1;i<=n;i++){
		list< pair<int,int> >::iterator itr=v[i].begin();
		while(itr!=v[i].end()){
			if(shortestdistance[i].first+(*itr).second<shortestdistance[(*itr).first].first){
				return i;
			}
			itr++;
		}
	}
	return -1;
}

void PrintNegativeCycle(int vertex, int startVertex)
{
    if (vertex == startVertex) {
        printf("%d ", vertex);
    } else if (shortestdistance[vertex].second == 0) {
        PrintNegativeCycle(startVertex, startVertex);
        printf("%d ", vertex);
    } else {
        PrintNegativeCycle(shortestdistance[vertex].second, startVertex);
        printf("%d ", vertex);
    }
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
	int negcycle=bellmanford(v,n,e,1);
	if(negcycle==-1){
		cout<<"No negative cycle"<<endl;
	}else{
		cout<<"Negative Cycle exist"<<endl;
		PrintNegativeCycle(shortestdistance[negcycle].second, negcycle);
	}
	for (int i = 1; i <= n; ++i) {
        printf("%d \t  %d \t\t\t\t    %d\n", i, shortestdistance[i].first,shortestdistance[i].second);
    }
	return 0;
}
