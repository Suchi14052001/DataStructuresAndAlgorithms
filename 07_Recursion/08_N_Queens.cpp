/*
Placing N chess queens on N*N chessboard so that no two queens attack eachother (Should not attack either on row, column or diagonally)
* Output the particular 2D matrix with queens

You can place only one queen per row. So for n=4
* Place a queen at first column in row 1
* Check for possibilities in row 2 and place it
* If there is no possibility in row 3, backtrack and correct the position in row2 and so on
*/ 

#include <iostream>
using namespace std;

bool canPlace(int board[][20], int n, int x, int y){
	// Check column wise
	for(int i=0; i<x; i++){
		if(board[i][y] == 1)
			return false;
	}
	
	// Check to left diagonal
	int i=x, j=y;
	while(i>=0 && j>=0){
		if(board[i][j] == 1)
			return false; 
		i--;
		j--;
	}
	
	// Check to right diagonal
	i=x, j=y;
	while(i>=0 && j<n){
		if(board[i][j] == 1)
			return false;
		i--;
		j++;
	}
	return true;
}

void printBoard(int board[][20], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << board[i][j] << " ";
		cout << endl; 
	}
}

bool solveNQueens(int n, int board[][20], int i=0){
	// i represents the current row we are in 
	
	// Base case - When i reaches n, it means that we found a solution. Print the state of the board and return
	if(i == n){
		printBoard(board, n);
		return true;
	}
	
	// Recursive case - Try to place one queen in each row. If needed, backtrack and try
	for(int j=0; j<n; j++){
		// Check if board[i][j] is a safe position (No queen should be there in diagonal left, right or up)
		if(canPlace(board, n, i, j)){
			board[i][j] = 1;
			bool success = solveNQueens(n, board, i+1);
			if(success)
				return true;
			else{
				// Backtrack
				board[i][j] = 0;
			}
		}
	}
	
	// You will come out of the loop without returning anything, only if there is no such position possible in current row. Then return false
	return false;
}

int main(){
	int board[20][20] = {0}, n = 4; // We are considering a max of 20*20 grid
	solveNQueens(n, board);
	return 0;
}

/*
Instead of printing the solution, if you want to find the number of solutions
* Define a global variable int count=0;

void solveNQueens(int n, int board[][20], int i=0){
	// i represents the current row we are in 
	
	// Base case - When i reaches n, it means that we found a solution. Print the state of the board and return
	if(i == n){
		count++;
		return;
	}
	
	// Recursive case - Try to place one queen in each row. If needed, backtrack and try
	for(int j=0; j<n; j++){
		// Check if board[i][j] is a safe position (No queen should be there in diagonal left, right or up)
		if(canPlace(board, n, i, j)){
			board[i][j] = 1;
			solveNQueens(n, board, i+1);
			board[i][j] = 0;
		}
	}
	
	// You will come out of the loop without returning anything, only if there is no such position possible in current row. Then return false
	return;
}

int nQueen(int n){
	count = 0;
	int board[20][20] = {0};  
	solveNQueens(n, board, 0);
	return count;
}

int main(){
	 // We are considering a max of 20*20 grid
	cout << nQueen(4);
	return 0;
} 
*/ 
