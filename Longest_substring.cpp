#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2,int m,int p){
	int L[m+1][p+1];
	for(int i=0;i<m+1;i++){
		L[0][i]=0;
		L[i][0]=0;
	}
	for(int i=1;i<m+1;i++){
		for(int j=1;j<p+1;j++){
			if(s1[i-1]==s2[j-1]){
				L[i][j]=L[i-1][j-1]+1;
			}else{
				L[i][j]=max(L[i-1][j],L[i][j-1]);
			}
		}
	}
	return L[m][p];
}

int main(void){
	string s1,s2;
	cin>>s1>>s2;
	cout<<lcs(s1,s2,s1.length(),s2.length());
	return 0;
}
