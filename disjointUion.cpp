#include<bits/stdc++.h>
using namespace std;

#define ll long long int
typedef unsigned long long int  ull;

const ll MAX=1e5+5;

ll arr[MAX];
ll ranks[MAX];

void initialize(){
    for(ll i=0;i<MAX;i++){
    	arr[i]=i;
    	ranks[i]=0;
	}
}

ll root(ll x){
	if(arr[x]!=x)
		arr[x]=root(arr[x]);
	return arr[x];
}

void union1(ll a,ll b){
    int xroot = root(a); 
    int yroot = root(b); 
  	if(xroot==yroot) return;
    if (ranks[xroot] < ranks[yroot]) 
        arr[xroot]= yroot; 
    else if (ranks[xroot] > ranks[yroot]) 
        arr[yroot] = xroot; 
  
    else
    { 
        arr[yroot] = xroot; 
        ranks[xroot]++; 
    } 
}

vector<ll> st;
int maxXor() 
{ 
    // Initialize index of 
    // chosen elements 
    int index = 0; 
    int n=st.size();
  
    // Traverse through all 
    // bits of integer  
    // starting from the most 
    // significant bit (MSB) 
    for (int i = 32-1; i >= 0; i--) 
    { 
        // Initialize index of 
        // maximum element and 
        // the maximum element 
        int maxInd = index; 
        int maxEle = INT_MIN; 
        for (int j = index; j < n; j++) 
        { 
            // If i'th bit of set[j] 
            // is set and set[j] is  
            // greater than max so far. 
            if ( (st[j] & (1 << i)) != 0  
                     && st[j] > maxEle ) 
                maxEle = st[j], maxInd = j; 
        } 
  
        // If there was no  
        // element with i'th 
        // bit set, move to 
        // smaller i 
        if (maxEle == INT_MIN) 
        continue; 
  
        // Put maximum element 
        // with i'th bit set  
        // at index 'index' 
        swap(st[index], st[maxInd]); 
  
        // Update maxInd and  
        // increment index 
        maxInd = index; 
  
        // Do XOR of set[maxIndex] 
        // with all numbers having 
        // i'th bit as set. 
        for (int j=0; j<n; j++) 
        { 
            // XOR set[maxInd] those 
            // numbers which have the 
            // i'th bit set 
            if (j != maxInd && 
               (st[j] & (1 << i)) != 0) 
                st[j] = st[j] ^ st[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        index++; 
    } 

        // Final result is  
    // XOR of all elements 
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= st[i]; 
    return res; 
} 

int main(void){
    initialize();
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        union1(a-1,b-1);
    }
	map<ll,ll> mp;
	for(ll i=0;i<n;i++){
		mp[root(i)]++;
	}
	map<ll,ll>::iterator itr;
	st.clear();
	for(itr=mp.begin();itr!=mp.end();itr++) st.push_back((*itr).second);
	cout<<maxXor()<<"\n";
    return 0;
}
