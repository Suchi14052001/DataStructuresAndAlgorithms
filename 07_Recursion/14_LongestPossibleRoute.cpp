/*
Given M*N matrix with 0s and 1s. 0s represent hurdles
* Return length of longest possible route from (0,0) to (m,n)
* Only allowed to move to adjacent cells which are not hurdles
* Cannot contain any diagonal moves
* Location once visited cannot be visited again
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<bool, int> findPath(int m, int n, vector<vector<int>> v, vector<vector<bool>> visited, int i=0, int j=0){
	// Base case
	if(i==m-1 && j==n-1) // Success case
		return make_pair(true,0);
	
	// Failure case
	if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || v[i][j]==0)
		return make_pair(false, INT_MAX);
		
	visited[i][j] = true; // Mark the cell visited first
	int res = INT_MIN;
	pair<bool, int> value;
	
	// Go left
	value = findPath(m, n, v, visited, i-1, j);
	if(value.first)
		res = max(res, value.second);
		
	// Go right
	value = findPath(m, n, v, visited, i, j+1);
	if(value.first)
		res = max(res, value.second);
		
	// Go up
	value = findPath(m, n, v, visited, i-1, j);
	if(value.first)
		res = max(res, value.second);
		
	// Go down
	value = findPath(m, n, v, visited, i+1, j);
	if(value.first)
		res = max(res, value.second);
		
	// Backtrack and return answer
	visited[i][j] = false;
	
	if(res == INT_MIN)
		return make_pair(false, INT_MAX);
	else
		return make_pair(true, res+1);
}

int findLongestPath(int m, int n, vector<vector<int>> v){
	vector<vector<bool>> visited = {};
    for(int i=0; i<m; i++){
		visited.push_back({});
		for(int j=0; j<n; j++)
			visited[i].push_back(false);
	}
	
	pair<bool, int> result = findPath(m, n, v, visited, 0, 0);
	return result.second;
}

int main(){
	int m = 3, n = 3;
	vector<vector<int>> v = {
		{1, 1, 1},
		{1, 1, 1},
		{0, 0, 1}
	};
	cout << "Length of longest path is: " << findLongestPath(m, n, v) << endl;
	return 0; 
}
