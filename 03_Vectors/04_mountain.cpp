/*
Given an array of n distinct integers, return the length of highest mountain
Mountain is defined as adjacent integers that are strictly increasing until a peak and are strictly decreasing from then
Atleast three numbers are required to form a mountain 

Identify peaks - elements for which number to left and right of it are smaller than current
At each peak, traverse back until current > next. Find the length. 
From that peak, traverse forward until current > next. Find the length
Do the same at all peaks
Add up both the lengths to get the length of highest mountain. O(N) time
*/
 
#include <iostream>
#include <vector>
using namespace std;

int mountain(vector<int> arr){
	int highest = 0;
	int length = 0;
	
	for(size_t i=1; i<arr.size()-1; i++){
		// Check if this vertex is a peak
		length = 0;
		if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
			// Peak
			int current = i;
			// For backward traversal
			while((current>=1) && (arr[current] > arr[current-1])){
				length ++;
				current--;
			}
			// One unit length difference above is covered since peak is counted twice
			
			// For forward traversal
			while((i<arr.size()-1) && (arr[i]>arr[i+1])){
				length ++;
				i++;
			}
			length++;
			
			if(highest<length)
				highest=length;
		}
	}
	return highest;
}

int main(){
	vector<int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};
	cout << "Length of highest mountain is: " << mountain(arr) << endl;
	
	return 0;
}
