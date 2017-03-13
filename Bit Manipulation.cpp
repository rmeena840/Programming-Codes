#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n){
	return !(n&(n-1));
}

int count_one(int n){
	int count=0;
	while(n){
		n=n&(n-1);
		count++;
	}
	return count;
}

bool check(int N,int i){
	if(N&(1<<i))
		return true;
	else
		return false;
}

void possibleSubsets(char A[],int n){
	for(int i=0;i<(1<<n);++i){
		for(int j=0;j<n;++j){
			if(i&(1<<j))
				cout<<A[j]<<' ';
		}
		cout<<endl;
	}
}

int largest_power(int n){
	n=n|(n>>1);
	n=n|(n>>2);
	n=n|(n>>4);
	n=n|(n>>8);
	n=n|(n>>16);
	return (n+1)>>1;
}

int main(void){
	int N;
	
	//Checking the power of 2.....
	cout<<"Enter a number to check it's power of 2?"<<endl;
	cin>>N;
	if(isPowerOfTwo(N))
		cout<<"yes, it's power of 2."<<endl;
	else
		cout<<"No, it's not power of 2."<<endl;
	//check for power of 2 ends here	
	
	//Count for number of 1 in bits generated
	cout<<"Enter the number to check number of 1 in bits?\n";
	cin>>N;
	cout<<"Number of 1 is: "<<count_one(N)<<endl;
	//count for number of 1 ends here
	
	//cheking the ith bit is set or not
	cout<<"Enter the number & ith value to check set or not"<<endl;
	int i;
	cin>>N>>i;
	if(check(N,i))
		cout<<"It is set\n";
		else
		cout<<"It is not set\n";
		char set[]={'a','b','c'};

	possibleSubsets(set,3);

	//Finding largest power of 2
	cout<<"Enter the number to find largest power of 2 of equal to it\n";
	cin>>N;
	cout<<largest_power(N)<<endl;
	return 0;
}
