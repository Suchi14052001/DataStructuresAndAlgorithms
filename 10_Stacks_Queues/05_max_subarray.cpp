/*
Given an array and integer k, find maximum for each and every contiguous subarray of size k

1. Brute force solution takes O(Nk) time
2. Using sliding window + deque -> Takes O(N) time 
*/ 

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void maxSubArrayK(vector<int> arr, int k){
	deque<int> Q(k); // Store indices in the deque rather than the value so that they let you check if index is out of k window
	/* Deque only stores useful elements
	   Two types of elements are not useful
	   * Element is outside the window. Any element that has index<=i-k will not be considered
	   * Or if we get a larger element than the current element
	*/
	int i;
	
	// 1. Process first K elements of the array
	for(i=0; i<k; i++){
		while(!Q.empty() && arr[i] > arr[Q.back()])
			Q.pop_back();
	}	Q.push_back(i);
		
	// 2. Process remaining elements of the array
	for(;i<(int)arr.size();i++){
		cout << arr[Q.front()] << " ";
		
		// Contraction from left when an element is outside the window
		while(!Q.empty() and Q.front()<=i-k)
			Q.pop_front();
		while(!Q.empty() && arr[i] >= arr[Q.back()])
			Q.pop_back();
		
		Q.push_back(i);
	}
}

int main(){
	vector<int> arr = {1,2,3,1,4,5,2,3,5};
	int k = 3;
	
	maxSubArrayK(arr, k);
	return 0;
}
