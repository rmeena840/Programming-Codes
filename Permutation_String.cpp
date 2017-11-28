#include<bits/stdc++.h>
using namespace std;

void swap(char *x,char *y){
	char temp=*x;
	*x=*y;
	*y=temp;
}

void permute(char *str,int l,int r){
	if(l==r){
		cout<<str<<endl;
	}else{
		for(int i=l;i<=r;i++){
			swap((str+l),(str+i));
			permute(str,l+1,r);
			swap((str+l),(str+i));
		}
	}
}

int main(void){
	char str[]="ABC";
	int n=strlen(str);
	permute(str,0,n-1);
	return 0;
}
