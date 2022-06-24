/*
Given an array of integers, count the total number of inversions
* Two elements a[i] and a[j] form an inversion if a[i]>a[j] and i<j
Eg: If the input array is [0, 5, 2, 3, 1], then the total number of inversions = 5
Inversion pairs will be (5,2), (5,3), (5,1), (2,1), (3,1)

1. Can use brute force approach in which you are comparing each element with all the elements coming after it. Takes O(N^2) time
2. Can use divide and conquer strategy, to find number of inversions for each element
   Split input array into part1 and part2. Calculate number of inversions needed in elements in part1, calculate number of inversions needed
   in elements in part2, then calculate number of cross inversions, one from part1 and one from part2 needed. Total number of inversions 
   would be the sum of these three
   * When you get an element in the right that is bigger than the left, then that element will form inversions with all the elements equal to
     and greater than element in left. (mid-i+1) in number. Calculate inversions while merging
   * Takes O(NlogN) time
*/ 

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int start, int end){
	// i points to start of the first array, j points to the start of second array
	// [start ..... mid], [mid+1 ..... end]
	
	int i=start, mid=(start+end)/2, j=mid+1, count=0;
	vector<int> temp; 
	
	while((i<=mid) && (j<=end)){
		if(arr[i] < arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			count += mid-i+1;
			temp.push_back(arr[j]);
			j++;
		}
	}
	
	// The above loop will end when one of the arrays get exhausted
	// Elements might have to be copied from left part of right part of the array
	
	// From the left part
	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}
	// From the right part
	while(j<=end){
		temp.push_back(arr[j]);
		j++;
	}
	
	// Finally copy changes from temp to original array for merge sort to see your changes
	i=0;
	for(int j=start; j<=end; j++){
		arr[j] = temp[i];
		i++;
	}
	return count;
}

int inversionCount(vector<int> &arr, int start, int end){
	// Base case
	if(start >= end)
		return 0;
		
	// Recursive case
	int mid = (start+end)/2;
	int C1 = inversionCount(arr, start, mid);
	int C2 = inversionCount(arr, mid+1, end);
	int CI = merge(arr, start, end);
	return C1+C2+CI;
}

int main(){
	vector<int> arr = {0, 5, 2, 3, 1};
	
	int start = 0, end = arr.size()-1;
	cout << "Inversion count is: " << inversionCount(arr, start, end);
	return 0;
}
