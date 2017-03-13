#include<bits/stdc++.h>
#define ll long long int
ll prime[32000];
using namespace std;

void setprimes(){
	ll temp,flag,j=0;
	for(ll i=2;i<32000;i++){
		flag=1;
		temp=sqrt(i);
		for(ll j=2;j<=temp;j++){
			if(!(i%j)){
				flag=0;
				break;
			}
		}
		if(flag){
			prime[j++]=i;
		}
	}
}

void printprimes(ll x,ll y){
	ll flag,temp;
	for(;x<=y;x++){
		flag=1;
		temp=sqrt(x);
		for(ll j=0;prime[j]<=temp;j++){
			if(!(x%prime[j])){
				flag=0;
				break;
			}
		}
		if(flag){
			cout<<x<<endl;
		}
	}
}

int main(void){
	setprimes();
	unsigned int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(n==1)
		n++;
		printprimes(n,k);
	}
	return 0;
}
