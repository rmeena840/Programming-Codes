#include<bits/stdc++.h>
using namespace std;

#define ll long long int
 
ll binary_search(int arr[],int bp,int n){
    ll low=0,high=n,mid;
    while(high>=low){
        mid=(low+high)/2;
        if(arr[mid]>bp)
            high=mid-1;
        else if(arr[mid]<=bp)
            low=mid+1;
    }
    return low;
}
 
 //recurseive binary search
 
 int binarys(int ar[],int l,int r,int x){
 	if(r>=l){
 		int mid=l+(r-l)/2;
 		if(ar[mid]==x)	return mid;
 		if(ar[mid]>x) return binarys(ar,l,mid-1,x);
 		return binarys(ar,mid+1,r,x);
	 }
	 return -1;
 }
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 50;
   int result = binary_search(arr,x,n-1);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
	if(binary_search(arr,arr+5,3)){
		cout<<"\nFound";
	}
   return 0;
}
