/*
Write a function that takes a input as array of distinct integers and returns kth smallest in the array

1. After doing something similar to quicksort, call quicksort on either left or right subarray based on K required and the index of pivot
*/ 

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end){
	int pivot = arr[end], i=start-1;
	
	for(int j=start; j<end; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	// Bring pivot element to current index
	swap(arr[i+1], arr[end]);
	return i+1;
}

int quickselect(vector<int> &arr, int start, int end, int k){
	int current = partition(arr, start, end);
	if(current+1==k)
		return arr[current];
	else if(current+1>k)
		return quickselect(arr, start, current-1, k);
	else
		return quickselect(arr, current+1, end, k);
}

int main(){
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	int start=0, end=arr.size()-1, k=4;
	
	cout << k << "th smallest element is: " << quickselect(arr, start, end, k);
	return 0;
}
