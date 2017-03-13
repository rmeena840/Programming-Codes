#include<bits/stdc++.h>
using namespace std;
void sieve(long long int x,long long int y){
	bool prime[y+1];
	memset(prime,true,sizeof(prime));
	
	for(int i=2;i*i<=y;i++){
		if(prime[i]){
			for(int j=i*2;j<=y;j+=i)
				prime[j]=false;
		}
	}
	for(int i=x;i<=y;i++)
	if(prime[i]){	
	cout<<i<<" "<<endl;
	}
}
int main(void){
	long long int  a,b,c,d;
	cout<<"Enter the number between you want to calculate prime number?";
	cin>>a>>b;
	sieve(a,b);
	return 0;
}
