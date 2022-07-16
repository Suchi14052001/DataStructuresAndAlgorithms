/*
Given a sudoku matrix 9*9. Our function should solve the sudoku matrix

* Need to try all solutions possible at all locations
*/ 

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> out;

void printSolution(vector<vector<int>> mat, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}

bool isSafe(vector<vector<int>> mat, int x, int y, int num, int n=9){
	// Check row wise and column wise
	for(int j=0; j<n; j++){
		if(mat[x][j] == num || mat[j][y] == num)
			return false;
	}
		
	// Check in that sub grid
	int sx = 3*(x/3), sy = 3*(y/3);
	for(int i=sx; i<sx+(n/3); i++){
		for(int j=sy; j<sy+(n/3); j++){
			if(mat[i][j] == num)
				return false;
		}
	}
	return true;
}

bool sudokuSolver(vector<vector<int>> mat, int i=0, int j=0, int n=9){
	// Base case
	if(i==n){
		printSolution(mat, n);
		out = mat;
		return true;
	}
	
	// Recursive case
	// If we are at the end of the row, then update row and column index
	if(j==n)
		return sudokuSolver(mat, i+1);
		
	// If the cell is prefilled - skip it
	if(mat[i][j] != 0)
		return sudokuSolver(mat, i, j+1);
		
	// For a cell that is not prefilled - Try out all numbers
	for(int num=1; num<=n; num++){
		// If it is safe to place this number or not
		if(isSafe(mat, i, j, num, n)){
			mat[i][j] = num;
			bool success = sudokuSolver(mat, i, j+1);
			
			if(success)
				return true;
		}
	}
	
	// Backtrack if no option works
	mat[i][j] = 0;
	return false;
}

vector<vector<int>> solveSudoku(vector<vector<int>> input){
	sudokuSolver(input);
	return out;
}

int main(){
	vector<vector<int>> mat {{5, 3, 0, 0, 7, 0, 0, 0, 0},
	 {6, 0, 0, 1, 9, 5, 0, 0, 0},
	 {0, 9, 8, 0, 0, 0, 0, 6, 0},
	 {8, 0, 0, 0, 6, 0, 0, 0, 3},
	 {4, 0, 0, 8, 0, 3, 0, 0, 1},
	 {7, 0, 0, 0, 2, 0, 0, 0, 6},
	 {0, 6, 0, 0, 0, 0, 2, 8, 0},
	 {0, 0, 0, 4, 1, 9, 0, 0, 5},
	 {0, 0, 0, 0, 8, 0, 0, 7, 9}};
	 
	 if(!sudokuSolver(mat))
		cout << "No solution exists" << endl;
	
	return 0;
}
