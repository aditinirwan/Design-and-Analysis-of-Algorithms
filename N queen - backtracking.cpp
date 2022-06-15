/* 1) Start in the leftmost column
2) If all queens are placed
    return true
3) Try all rows in the current column. 
   Do following for every tried row.
    a) If the queen can be placed safely in this row 
       then mark this [row, column] as part of the 
       solution and recursively check if placing
       queen here leads to a solution.
    b) If placing the queen in [row, column] leads to
       a solution then return true.
    c) If placing queen doesn't lead to a solution then
       unmark this [row, column] (Backtrack) and go to 
       step (a) to try other rows.
4) If all rows have been tried and nothing worked,
   return false to trigger backtracking. */
   
#include<bits/stdc++.h>
using namespace std;
#define n 4

bool is_safe(int board[n][n],int row,int col) {
	//left side row
	for(int i=0;i<col;i++) {
		if(board[row][i]) {
			return false;
		}
    }
	//left side upper diagonal 
	for(int i=row;i>=0;i--) {
		for(int j=col;j>=0;j--) {
			if(board[i][j]) {
				return false;
			}
		}
    }
	//left side lower diagonal
	for(int i=row;i<n;i++) {
		for(int j=col;j>=0;j--) {
			if(board[i][j]) {
				return false;
			}
		}
	}
	return true;
}

bool rec_Nqueen(int board[n][n],int col) {
	if(col>=n) {
		return true; 
	}
	for(int i=0;i<n;i++) {
		if(is_safe(board,i,col)) {
			board[i][col]=1;
			if(rec_Nqueen(board,col+1)) {
			    return true;
		    }
		board[i][col]=0;
	    }
   }	
	return false;
}

bool backtrack_Nqueen() {
	int board[n][n]= { { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 },
                   { 0, 0, 0, 0 } };
    if(rec_Nqueen(board,0)==false) {
    	cout<<"No solution found";
    	return false;
	}
	cout<<"solution is: "<<endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	return true;
}

int main() {
	backtrack_Nqueen();
	return 0;
}
