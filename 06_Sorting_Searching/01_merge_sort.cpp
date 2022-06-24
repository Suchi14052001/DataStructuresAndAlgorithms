/*
In merge sort (Divide and Conquer algorithm), step one is to divide the array at the midpoint, step two is to call mergesort function 
recursively on both left and right sub arrays. After getting sorted left and right subparts, merge both of them into a single sorted array 
*/ 

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int end){
	// i points to start of the first array, j points to the start of second array
	// [start ..... mid], [mid+1 ..... end]
	
	int i=start, mid=(start+end)/2, j=mid+1;
	vector<int> temp; 
	
	while((i<=mid) && (j<=end)){
		if(arr[i] < arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
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
	return;
}

void mergesort(vector<int> &arr, int start, int end){
	// Base case
	if(start >= end)
		return;
		
	// Recursive case
	int mid = (start+end)/2;
	mergesort(arr, start, mid);
	mergesort(arr, mid+1, end);
	return merge(arr, start, end);
}

int main(){
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	
	int start = 0, end = arr.size()-1;
	mergesort(arr, start, end);
	
	// After sorting, printing the sorted array
	for(int i:arr)
		cout << i << " ";
	cout << endl;
	return 0;
}

/*
Try to dry run the code with the help of recursion tree and stack of calls that are executed to better understand the flow of merge sort
* Remember that recursion works in depth first manner
*/ 
