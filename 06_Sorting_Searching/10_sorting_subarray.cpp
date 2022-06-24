/*
Given an array, return two indices denoting starting and ending indices of smallest subarray that needs to be sorted in place to make
entire input array to be sorted. Return [-1,-1] if input array is already sorted
*/

#include <vector>
#include <iostream>
using namespace std;

pair<int,int> subarraySorting(vector<int> a){
	pair<int, int> result;
	int start = a.size()-1, end = 0;
	
	for(size_t i=0; i<a.size(); i++){
		if(i==0){
			if(a[i] > a[i+1]){
				start = min(start, a[i]);
				end = max(end, a[i]);
			}
		}else if(i==(a.size()-1)){
			if(a[i] < a[i-1]){
				start = min(start, a[i]);
				end = max(end, a[i]);
			}	
		}else{
			if((a[i] > a[i+1]) || (a[i] < a[i-1])){
				start = min(start, a[i]);
				end = max(end, a[i]);
			}
		}
	}
	
	// Now, find the correct positions of these start and end elements
	int i=0,j=a.size()-1;
	while(start >= a[i])
		i++;
	while(end <= a[j])
		j--;
	
	if(i==(int)(a.size()-1))
		result.first = -1, result.second = -1;
	else{
		result.first = i;
		result.second = j;
	}
	return result;
}

int main(){
	vector<int> arr = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
	cout << "(start, end) = (" << subarraySorting(arr).first << ", " << subarraySorting(arr).second << ")\n";
	
	return 0;
}
