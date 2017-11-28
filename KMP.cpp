#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat,int M,int *lps){
	int len=0;
	lps[len]=0;
	int i=1;
	while(i<M){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}else{
			if(len!=0){
				len=lps[len-1];
			}else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp(string txt,string pat){
	int M=pat.length();
	int N=txt.length();
	int lps[M];
	computeLPS(pat,M,lps);
	int i=0;
	int j=0;
	while(i<N){
		if(pat[j]==txt[i]){
			j++;
			i++;
		}		
		if(j==M){
			cout<<"Found at "<<i-j<<endl;
			j=lps[j-1];
		}else if(i<N && pat[j]!=txt[i]){
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}

int main(void){
	string txt,pat;
	txt="AAAAABAAABA";
	pat="AAAA";
	kmp(txt,pat);
	return 0;
}
