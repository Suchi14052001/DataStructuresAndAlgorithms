/*
Given a set of non-negative integers and a sum, determine if there is a subset of given set with sum equal to given sum
Count number of such subsets possible if it exists
*/ 

#include <iostream>
#include <vector>
using namespace std;

int numSubsets(int index, vector<int> arr, int remSum){
	if(index==(int)arr.size())
		return (remSum==0) ? 1 : 0;

	int a = numSubsets(index+1, arr, remSum-arr[index]);
	int b = numSubsets(index+1, arr, remSum);
	return a+b;
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5};
	int targetSum = 10;
	cout << "Number of ways to get sum " << targetSum << " is: " << numSubsets(0, arr, targetSum) << endl;	
	return 0;
}
