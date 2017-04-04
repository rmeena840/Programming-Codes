#include<bits/stdc++.h>
using namespace std;

int lookup[100];

void initialize(){
	memset(lookup,NULL,sizeof lookup);
}

int fib(int n){
	if(lookup[n]==NULL){
		if(n<=1){
			lookup[n]=n;
		}else{
			lookup[n]=fib(n-1)+fib(n-2);
		}
	}
	return lookup[n];
}

int main(void){
	initialize();
	cout<<"Fibonacci number is: "<<fib(5);
	return 0;
}
