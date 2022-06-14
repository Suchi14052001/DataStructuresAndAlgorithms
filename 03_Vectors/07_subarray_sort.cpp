/*
Given an array of size atleast 2, find the smallest subarray that needs to be sorted in place so that entire input array becomes sorted
If the input array is already sorted, return [-1, 1] else return start and end index of the smallest subarray

Simple approach is to sort the array and check what elements are not changing positions after sorting. Takes O(nLogn)
Find smallest and largest element that is out of order. Out of order can be checked by a[i]<a[i-1] or a[i]>a[i+1]
Then find the right positions of these smallest and largest elements. Takes O(N) time
*/

#include <vector>
#include <iostream>
using namespace std;

pair<int, int> subarraySort(vector<int> arr){
	pair<int, int> result;
	int start = arr.size()-1, end = 0;
	
	for(size_t i=0; i<arr.size(); i++){
		if(i==0){
			if(arr[i] > arr[i+1]){
				start = min(start, arr[i]);
				end = max(end, arr[i]);
			}
		}else if(i==(arr.size()-1)){
			if(arr[i] < arr[i-1]){
				start = min(start, arr[i]);
				end = max(end, arr[i]);
			}	
		}else{
			if((arr[i] > arr[i+1]) || (arr[i] < arr[i-1])){
				start = min(start, arr[i]);
				end = max(end, arr[i]);
			}
		}
	}
	
	// Now, find the correct positions of these start and end elements
	int i=0,j=arr.size()-1;
	while(start >= arr[i])
		i++;
	while(end <= arr[j])
		j--;
	
	if(i==(int)(arr.size()-1))
		result.first = -1, result.second = 1;
	else{
		result.first = i;
		result.second = j;
	}
	return result;
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
	cout << "(start, end) = (" << subarraySort(arr).first << ", " << subarraySort(arr).second << ")\n";
	
	return 0;
}
