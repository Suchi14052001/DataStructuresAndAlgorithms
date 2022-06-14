/*
Given a vector of integers, return a vector of same size where each element in output array is equal to product of every other number
in input array
output[i] = product of every number in input array other than input[i]
*/

#include <vector>
#include <iostream>
using namespace std;

vector<int> productArray(vector<int> arr){
    vector<int> output(arr.size(),1);
	vector<int> left(arr.size(),1), right(arr.size(),1);
	
	for(size_t i=1; i<arr.size(); i++)
		left[i] = left[i-1] * arr[i-1];
		
	for(int i=arr.size()-2; i>=0; i--)
		right[i] = right[i+1] * arr[i+1];
    
    for(size_t i=0; i<arr.size(); i++)
		output[i] = left[i] * right[i];
    
    return output;
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5};
	vector<int> out = productArray(arr);
	
	for(int element: out)
		cout << element << endl;
	return 0; 
}
