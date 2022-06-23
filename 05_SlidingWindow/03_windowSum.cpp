/*
Another approach, say if array = [1, 3, 2, 5] Then prefix sum array = [1, 4, 6, 11]
Now since areas are non-negative, prefix sum array will be non-decreasing sequence, can use binary search
For every i in prefix sum array, find a j ahead of it such that pr(j) - pr(i) = K
Overall complexity would be O(NlogN) time
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void windowSum(vector<int> arr, int sum){
	vector<int> ps; // for prefix sum
	ps.push_back(arr[0]);

	for(int i=1; i< (int)arr.size(); i++)
		ps.push_back(ps[ps.size()-1]+arr[i]);
		
	for(int i=0; i< (int)arr.size(); i++){
		for(int j=i+1; j<(int)arr.size(); j++){
			if(ps[j]-ps[i] == sum)
				cout << "(" << i+1 << "," << j << ")\n";
		}
	}

	for(int i=0; i<(int)ps.size(); i++){
		if(ps[i]==sum)
			cout << "(0," << i << ")\n";
	}
	return;
}

int main(){
	vector<int> arr = {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10};
	          // ps = [0, 5, -2, -1, -5, 2, 8, 9, 13, 14, 24] 
	int sum = 15;
	cout << "(start index, end index): \n";
	windowSum(arr, sum);
	return 0;
}
