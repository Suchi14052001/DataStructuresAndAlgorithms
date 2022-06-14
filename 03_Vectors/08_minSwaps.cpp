/*
Given an array of size N, find the minimum number of swaps needed to make the array sorted

For a cycle containing n elements, (n-1) swaps will be needed 
*/

#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int minSwaps(vector<int> arr){
	int swaps = 0;
	
	// Original values and positions of array 
	pair<int, int> original[arr.size()];
	for(size_t i=0; i<arr.size(); i++){
		original[i].first = arr[i];
		original[i].second = i;
	}
	
	// Perform sorting based on these values
	sort(original, original+(arr.size()-1));
	
	vector<bool> visited(arr.size()-1, false);
	
	// Iterate through the new indices
	for(size_t i=0; i<arr.size()-1; i++){
		// If element is visited or in right position
		if(visited[(int)i] == true || (int)i==original[(int)i].second)
			continue;
		
		// If the element is visited for the first time
		int current = i, elementsInCycle = 0;
		while(visited[current] == false){
			visited[current] = true;
			current = original[current].second;
			elementsInCycle++;
		}
		swaps += (elementsInCycle-1);
	}
	
	return swaps;
}

int main(){
	vector<int> arr = {5, 4, 3, 2, 1};
	cout << "Number of minimum swaps: " << minSwaps(arr) << endl;
	return 0;
}
