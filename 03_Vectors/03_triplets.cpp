/*
 Given an array containing N integers and S denoting the target sum	
 Find all distinct triplets which add upto S
 Numbers in the triplet and the triplets must be ordered
 
 Brute force approach is to use three loops, O(N^3)
 Iterate over each element, and work on the remaining array as a pair sum problem. This takes O(N^2) time and O(N) space
 Sort the array, then iterate over entire array and solve remaining array as a pair sum problem using 2 pointer approach. O(N^2) time
 */
 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void triplets(vector<int> arr, int sum){
	
	// This is done inorder to ensure that there are atleast two elements in the remaining set
	for(size_t i=0; i<arr.size()-3; i++){ //When we are comparing with sizes, it is better to initialise i with size_t or unsigned
		int diff = sum - arr[i];
		
		int low = i+1, high = arr.size()-1;
		while(low < high){
			if(low+high == diff){
				cout << "(" << arr[i] << "," << low << "," << high << ")\n";
				low++;
				high--;
			}else if(low+high < diff)
				low++;
			else if(low+high > diff)
				high--;
		}
	}
	
	//Instead of this, to push vector into a vector you can use, vec.push_back({1, 2, 3})
}

int main(){
	vector<int> arr = {4, 5, -1, 5, 2, 7, 6};
	int sum = 8;
	
	sort(arr.begin(), arr.end());
	triplets(arr, sum);
	return 0;
}
