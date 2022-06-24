/*
* Average case time complexity is O(NlogN), worst case can take upto O(N^2)
* Divide and Conquer algorithm
* Chooses a pivot in first step (can be first element or last element or any random element - here we are picking the last element), next 
  step is to partition the array in such a way that, all elements less than pivot lie to the left of it and all elements greater than the
  pivot lie to the right of it. Then the pivot will be placed in the correct position. Finally, recursively sort the left and right parts of 
  the array
  * Point i to -1 and j to 0. Compare pivot with arr[j], if arr[j]>pivot, do j++, else do i++ and swap arr[i] and arr[j]. After the entire 
    array is processed, add the pivot at i+1 index. Pivot will be in a sorted location. 
* Space complexity is not O(1) as it uses stack memory for recursion
* A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the 
  input array to be sorted. Quick sort is an unstable sorting algorithm
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

void quicksort(vector<int> &arr, int start, int end){
	// Base case
	if(start >= end) // If there are zero or one elements in the input array
		return;
		
	// Recursive case
	// Here, when we make a call to partition method, it keeps the pivot in its right position and returns its correct position
	// arr[start...p-1] will now contain elements <pivot and arr[p+1...end] will now contain elements >pivot
	
	int current = partition(arr, start, end);
	quicksort(arr, start, current-1);
	quicksort(arr, current+1, end);
}

int main(){
	vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
	int start=0, end=(int)arr.size()-1;
	quicksort(arr, start, end);
	
	// Print the sorted output
	for(int i:arr)
		cout << i << " ";
	cout << endl;
	return 0;
}
