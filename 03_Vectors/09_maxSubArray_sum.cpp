/*
Given a input vector, print max subarray that can be formed
Subarray is consecutive segment of array
*/

#include <vector>
#include <iostream>
using namespace std;

int maxSubarraySum(vector<int> arr){
    int maxSum = arr[0], sum = arr[0], count=0;
    
    // Corner case - to return zero when all elements are <0
    for(auto element:arr){
		if(element<0)
			count++;
	}
	if(count == (int)arr.size())
		return 0;
    
    for(size_t i=1; i<arr.size()-1; i++){
		sum = max(sum + arr[i], arr[i]);
		maxSum = max(maxSum, sum);
	}
    return maxSum;
}

int main(){
	vector<int> arr = {-1, 2, 3, 4, -2, 6, -8, 3};
	cout << "Sum of maximum subarray is: " << maxSubarraySum(arr) << endl;
	return 0; 
}
