/*
Given an unsorted array of integers, find the number of subarrays having sum exactly equal to K
*/ 

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cntSubarrays(vector<int> arr, int k){
	vector<int> ps; // for prefix sum
	ps.push_back(arr[0]);
	int count=0;

	for(int i=1; i< (int)arr.size(); i++)
		ps.push_back(ps[ps.size()-1]+arr[i]);
	
	for(int i=0; i<(int)arr.size(); i++){
		for(int j=i+1; j<(int)arr.size(); j++){
			if(ps[j]-ps[i] == k)
				count++;
		}
	}
	
	for(int i: ps){
		if(i==k)
			count++;
	}
	return count;
}

int main(){
	vector<int> arr = {10, 2, -2, -20, 10};
	          // ps = [10, 12, 10, -10, 0] 
	int sum = -10;
	cout << "Number of subarrays having sum K is: " << cntSubarrays(arr, sum);
	return 0;
}
