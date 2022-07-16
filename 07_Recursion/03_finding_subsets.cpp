/*
Given a string, find all subsets/subsequences of the given string
* For a string of length N, there will be 2^N subsets
* Substring means continuous part of the array whereas subsequence/subset may be discontinuous
*/ 

#include <string>
#include <iostream>
using namespace std;

void findingSubsets(string str, int index=0, string current=""){
	if(index==(int)str.length()){
		cout << current << endl;
		return;
	}
	
	findingSubsets(str, index+1, current+str[index]);
	findingSubsets(str, index+1, current);
}

int main(){
	string input = "abc";
	findingSubsets(input);
}
