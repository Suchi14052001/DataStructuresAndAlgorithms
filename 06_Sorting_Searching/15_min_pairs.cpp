/*
Given two non-empty arrays, find pair of numbers one from each array whose abs diff is minimum

1. Can use brute force approach using two loops which takes complexity O(NM) where N is length of first array, M is length of second array
2. Using binary search. Sort the second array. Use lower bound function by iterating through first array and find minimum difference
   Takes time complexity O(NlogN + MlogN)
*/ 

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

pair<int, int> minPairs(vector<int> v1, vector<int> v2){
	pair<int, int> result;
	int min_diff=INT_MAX;
	
	for(int i=0; i<(int)v1.size(); i++){
		int low = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
		
		if(low >= 1 && min_diff > v1[i] - v2[low-1]){
			min_diff = v1[i] - v2[low-1];
			result.first = v1[i], result.second = v2[low-1];
		}
		
		if(low != (int)v2.size() && min_diff > v2[low] - v1[i]){
			min_diff = v2[low] - v1[i];
			result.first = v1[i], result.second = v2[low];
		}
	}
	return result;
}

int main(){
	vector<int> v1{-1, 5, 10, 20, 3};
	vector<int> v2{26, 134, 135, 15, 17};
	
	// Sort the second array
	sort(v2.begin(), v2.end());
	pair<int, int> result = minPairs(v1, v2);
	cout << "(i,j) = (" << result.first << "," << result.second << ")\n";
	return 0;
}
