#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll binaryexpo(ll x,ll n){
	ll result=1;
	while(n>0){
		if(n%2==1)
			result=result*x;
		x=x*x;
		n=n/2;
	}
	return result;
}

ll modularexpo(ll x,ll n,ll m){
	ll result=1;
	while(n>0){
		if(n%2==1)
			result=(result*x)%m;
		x=(x*x)%m;
		n=n/2;
	}
	return result;
}

ll gcd(ll A,ll B){
	if(B==0)
		return A;
	else return gcd(B,A%B);
}

int d,x,y;

void extendedeuclid(ll A,ll B){
	if(B==0){
		d=A;
		x=1;
		y=0;
	}else{
		extendedeuclid(B,A%B);
		int temp=x;
		x=y;
		y=temp-(A/B)*y;
	}
}

int main(void){
	ll m=10^9+7;
	cout<<binaryexpo(2,9999998)<<endl;
	cout<<modularexpo(2,999999,m)<<endl;
	cout<<gcd(16,10)<<endl;
	
	//Extended Euclid
	extendedeuclid(16,10);
	cout<<"d="<<d<<endl;
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;	
	return 0;
}
