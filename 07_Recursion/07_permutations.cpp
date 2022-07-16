/*
Given a string s, find all permutations of that string

Eg: If given input string is "abc" then 
* a can be at the first position, call the recursive function on the smaller string
Swap each letter with all possible
*/ 

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

set<string> out;

void permutations(string input, string curr="", int i=0){
	if(curr.length() == input.length()){
		out.insert(curr);
		return;
	}
	
	for(int j=i; j<(int)input.length(); j++){
		swap(input[j], input[i]);
		permutations(input, curr + input[i], i+1);
	}
}

vector<string> findSortedPermutations(string input){
	out.clear();
	permutations("abc");
	return {out.begin(), out.end()};
}

int main(){
	vector<string> res = findSortedPermutations("acb");
	for(auto i: res)
		cout << i << endl;
	return 0;
}
