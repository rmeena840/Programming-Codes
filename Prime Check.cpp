#include<bits/stdc++.h>
using namespace std;

int main(void){
	cout<"Enter any number?\n";
	long long int a;
	int flag=0;
	cin>>a;
	for(int b=2;b<=sqrt(a);b++){
		if(a%b==0){
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"Not Prime";
	else
	cout<<"Prime";
	return 0;
}
