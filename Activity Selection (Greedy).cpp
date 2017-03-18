#include<bits/stdc++.h>
using namespace std;

struct job{
	char id;
	int start;
	int finish;
};

//sorting in increasing order
bool sortbysecond(job s1,job s2){
	return (s1.finish < s2.finish);
}

void printActivity(job arr[],int n){
	sort(arr,arr+n,sortbysecond);
	int track=0;
	for(int i=0;i<n;i++){		
		if(track<=arr[i].start){
			track=arr[i].finish;
			cout<<arr[i].id<<" ";
		}
	}
}

int main(void){
	job arr[]={{'A',0,6},{'B',3,4},{'C',1,2},{'D',5,9},{'E',5,7},{'F',8,9}};
	printActivity(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}
