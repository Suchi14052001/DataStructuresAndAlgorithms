/*
You are given M*N matrix which is row wise and column wise sorted. Search the given index of given integer K in the matrix
Return {x,y} where x is the row index and y is the column index
*/ 

#include <iostream>
#include <vector>
using namespace std;

pair<int,int> search(int m, int n, vector<vector<int>> v, int k){
    if(k<v[0][0] || k>v[m-1][n-1])
		return make_pair(-1, -1);
	
	int i=0, j=n-1;
	while(i<=n-1 && j>=0){
		if(v[i][j] == k)
			return make_pair(i, j);
		else if(v[i][j] > k)
			j--;
		else
			i++;
	}
	return make_pair(-1, -1);
}

int main(){
	int m=3, n=3;
	vector<vector<int>> v = {{1, 4, 9}, {2, 5, 10}, {6, 7, 11}};
	int key = 10;
	
	pair<int,int> res = search(m, n, v, key);
	cout << "Location of " << key << " is: (" << res.first << "," << res.second << ")\n";
	return 0; 
}
