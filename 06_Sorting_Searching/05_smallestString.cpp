/*
Given a list of n strings, concatenate them such that resulting string is lexicographically smallest
* Given N strings, there are N! ways to concatenate strings 

1. Use a sorting based approach like merge sort, and use custom sort function to return a+b < b+a
   This returns the smallest concatenation among a and b strings
*/ 

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool customConcat(string a, string b){
	return a+b < b+a;
}

int main(){
	string arr[] = {"a", "ab", "aba"};
	string result = "";
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+n, customConcat);

	// Concat and print output
	for(string current:arr)
		result+=current;
	cout << "Lexicographically smallest string is: " << result << endl;
	return 0;
}
