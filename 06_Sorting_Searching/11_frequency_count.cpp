/*
Given a sorted array which can have repeated elements and an element K, define frequency of given element

1. Using binary search, we want to find the index of first and last occurence of element K. Then frequency would be last - first + 1
   To calculate lower bound, if a[mid]==key, call binarySearch on left of array, update lower bound. Repeat the same and update upper bound
*/ 

#include <vector>
#include <iostream>
using namespace std;

int binarySearch(vector<int> arr, int key){
	int start = 0, end = (int)arr.size()-1;
	while(start<=end){
		int mid = (start+end)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<key)
			start = mid+1;
		else
			end = mid-1;
	}
	return -1;
}

int main(){
	vector<int> input = {0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
	int key = 2, freq=-1, i, j;
	int index = binarySearch(input, key);
	
	if(index==-1)
		freq=0;
	else{
		i = index - 1;
		j = index + 1;
		while(i>=0 && input[i]==key)
			i--;
		while(j<=(int)input.size()-1 && input[j]==key)
			j++;
		freq=j-1-i;
	}
	cout << "Frequency of " << key << " is: " << freq << endl;
	return 0;
}
