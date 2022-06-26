/*
Takes input as sorted array of distinct integers which is rotated about pivot point. Find index of given element
1. Modified binary search algorithm, compute mid and check if arr[mid]==key, if yes return else there are two cases
	* Mid may lie on Line 1 (a[start]<=a[mid])
		* To further make a call on left  {if(key>=a[start] && key<=a[mid]) then end = mid-1} 
		* To further make a call on right {else start = mid+1}
	* Mid may lie on Line 2 
		* To further make a call on right {if(key>=a[mid] && key<=a[end]) then start = mid+1} // We can make comparison on sorted line
		* To further make a call on left  {else end = mid-1}
*/ 

#include <vector>
#include <iostream>
using namespace std;

int rotatedSearch(vector<int> arr, int key, int start, int end){
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
	vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3}; 
	int key = 2, start, end, i=1;
	
	for(i=1; i<(int)arr.size();){
		if(arr[i]>=arr[i-1])
			i++;
		else
			break;
	}
	
	if(key>=arr[i] && key<=arr[0])
		start=i, end=(int)arr.size()-1;
	else
		start=0, end=i-1;
	cout << "Index of " << key << " is: " << rotatedSearch(arr, key, start, end) << endl;
	return 0;
}
