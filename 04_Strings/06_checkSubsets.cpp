/*
Given two non-empty strings, determine whether the second string is a subsequence of the first one

1. One approach is to find all subsets and check if second string is one of those subsets - very inefficient - Takes (2^N)*N time
2. Have two pointers, one pointing to the end of second string, one pointing to the end of first string - Takes O(N) time
*/

#include <string>
#include <iostream>
using namespace std;

int main(){
	string s1, s2;
	cout << "Enter the first string: \n";
	getline(cin, s1);
	cout << "Enter the second string: \n";
	getline(cin, s2);
	
	int current=0, index, count=0;
	for(int i=0; i<(int)s2.length(); i++){
		index = s1.find(s2[i], current);
		if(index != -1)
			count++;
		current++;
	}
	
	if(count==(int)s2.length())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	return 0;
}
