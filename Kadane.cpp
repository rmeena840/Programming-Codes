#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
	int max_so_far=INT_MIN,max_end_here=0;
	for(int i=0;i<n;i++){
		max_end_here=max_end_here+arr[i];
		max_so_far=max(max_so_far,max_end_here);
		if(max_end_here<0)
			max_end_here=0;
	}
	return max_so_far;
}

int main(void){
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "Maximum contiguous sum is " << kadane(a, n);
    
	return 0;
}
