/*
Given an integer N and a grid N*N
* Cells of this grid are numbered row wise from 1 to N^2
* Rat wants to travel from cell 1 to cell N^2
* It can move only in right or down direction and some of the cells are blocked
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solveMaze(int n, vector<vector<char>> c, int row, int col, vector<vector<int>> places, vector<int> &sol){
	if(row==n-1 && col==n-1)
		return true;

	if(row==n || col==n)
		return false;
	
	// Move right
	if(col<=n-2 && c[row][col+1]!='X'){
		if(solveMaze(n,c,row,col+1,places,sol)){
			sol.push_back(places[row][col+1]);
			return true;
		}
	}
	
	//Move down
	if(row<=n-2 && c[row+1][col]!='X'){
		if(solveMaze(n,c,row+1,col,places,sol)){
			sol.push_back(places[row+1][col]);
			return true;
		}
	}
	return false;
}

vector<int> findPath(int n, vector<vector<char>> c){
	vector<vector<int>> places={};
    int k=1;
    
    for(int i=0; i<n ; i++){
		places.push_back({});
		for(int j=0; j<n; j++){
			places[i].push_back(k);
			k++;
		}
	}
	
	vector<int> sol;
	solveMaze(n, c, 0, 0, places, sol);
	sol.push_back(1);
	reverse(sol.begin(), sol.end());
	return sol;
}

int main(){
	vector<vector<char>> c = {
		{'O', 'O', 'X', 'O'},
		{'O', 'X', 'O', 'O'},
		{'O', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'O'}
	};
	vector<int> result = findPath(4,c);	
	for(auto i:result)
		cout << i << endl;
	
	return 0; 
}
