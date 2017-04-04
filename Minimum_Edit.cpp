#include<bits/stdc++.h>
using namespace std;

int min_edit(string s1,string s2,int m,int p){
	int lookup[m+1][p+1];
	for(int i=0;i<m+1;i++){
		lookup[0][i]=i;
	}
	for(int i=0;i<p+1;i++){
		lookup[i][0]=i;
	}
	for(int i=1;i<m+1;i++){
		for(int j=1;j<p+1;j++){
			if(s1[i-1]==s2[j-1])
					lookup[i][j]=lookup[i-1][j-1];
			else
					lookup[i][j]= 1+min(min(lookup[i][j-1],lookup[i-1][j]),lookup[i-1][j-1]);
		}
	}
	return lookup[m][p];
}

int main(void){
	string s1,s2;
	cin>>s1>>s2;
	cout<<min_edit(s1,s2,s1.length(),s2.length());
	return 0;
}
