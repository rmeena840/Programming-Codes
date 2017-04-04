#include<bits/stdc++.h>
using namespace std;
int board[4];

void printboard(int n){
	static int solno=1;
	cout<<"Solution Number: "<<solno++<<endl;
	for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < board[i]; k++)
            printf("  ");
        printf("%2d\n", board[i]+1);
    }
}

bool place(int row,int col){
	for(int i=0;i<row;i++){
		if(board[i]==col || abs(board[i]-col)==abs(i-row))
			return false;
	}
	return true;
}

void Nqueen(int row,int n){
	for(int col=0;col<n;col++){
		if(place(row,col)){
			board[row]=col;
			if(row==n-1)
				printboard(n);
			else
				Nqueen(row+1,n);
		}
	}
}

int main(void){
	Nqueen(0,4);
	return 0;
}
