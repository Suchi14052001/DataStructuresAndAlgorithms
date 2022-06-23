/*
Given an array of integers and an integer K, return a vector containing maximum for each and every contiguous subarray of size K
*/ 

#include <vector>
#include <iostream>
using namespace std;

vector<int> maxInWindow(vector<int> input,int k){
	vector<int> result;
	int current, j; 
	
	if((int)input.size()<k)
		return {};
		
	for(int i=0; i<=(int)input.size()-k; i++){
		current = input[i];
		j=i;
		for(j=0; j<k; j++){
			if(current<input[i+j])
				current = input[i+j];
		}
		result.push_back(current);
	}
	return result;
}

int main(){
	vector<int> result;
	vector<int> input = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int k = 3; 
	result = maxInWindow(input, k);
	
	for(int i: result)
		cout << i << " ";
	cout << endl;
	return 0;
}
