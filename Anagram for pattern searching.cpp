#include<bits/stdc++.h>
using namespace std;

#define MAX 256

bool compare(char txt[],char pat[]){
	for(int i=0;i<MAX;i++)
		if(pat[i]!=txt[i])
			return false;
	return true;
}

void search(char pat[],char txt[]){
	int M=strlen(pat),N=strlen(txt);
	char countP[MAX]={0},countTW[MAX]={0};
	
	for(int i=0;i<M;i++){
		countP[pat[i]]++;
		countTW[txt[i]]++;
	}
	
	for(int i=M;i<N;i++){
		if(compare(countTW,countP))
			cout<<"Found at "<<(i-M)<<endl;
		countTW[txt[i]]++; //Add current char
		countTW[txt[i-M]]--; //Delete previous char
	}
	//check for last window
	if(compare(countTW,countP))
		cout<<"Found at "<<(N-M)<<endl;
}

int main(void){
	char txt[] = "BACDGABCDA";
    char pat[] = "ABCD";
    search(pat, txt);
    return 0;
	return 0;
}
