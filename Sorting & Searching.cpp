#include<bits/stdc++.h>
#define SIZE 5
using namespace std;

int main(void){
	int ar[SIZE]={2,3,4,5,1};
	sort(ar,ar+SIZE);
	int a;
	cout<<"Number you want to search?\n";
	cin>>a;
	if(binary_search(ar,ar+sizeof(ar)/sizeof(ar[0]),a))
		cout<<"Found";
		else
		cout<<"Not found";
	return 0;
}
