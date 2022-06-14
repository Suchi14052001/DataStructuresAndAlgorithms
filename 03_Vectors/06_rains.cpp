/*
Given n non-negative integers representing an elevation map where the width of each bar is 1.
Compute how much water it can trap after raining

Amount of water that gets trapped at each bar is (min(highest bar on left, highest bar on right) - height of current bar)
At each position, if this is done it takes O(N*N) time
Build two arrays left and right and store what is the highest level we encountered so far. Takes O(N) time
*/

#include <vector>
#include <iostream>
using namespace std;

int rains(vector<int> arr){
	int water = 0;
	vector<int> left(arr.size(), 0), right(arr.size(), 0);
	
	if(arr.size()<=2)
		return 0; // Corner case when no water can be trapped
	
	// For building the left array
	left[0] = arr[0];
	for(unsigned i=1; i<arr.size(); i++)
		left[i] = max(left[i-1], arr[i]);
	
	// For building the right array
	right[arr.size()-1] = arr[arr.size()-1];
	for(int i=arr.size()-2; i>=0; i--){
		right[i] = max(arr[i], right[i+1]);
	}
	
	// For calculating water
	for(size_t i=0; i<arr.size(); i++)
		water += (min(left[i], right[i]) - arr[i]);
	
	return water;
}

int main(){
	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << "Number of units of water that get trapped is: " << rains(arr) << endl;
	
	return 0;
}
