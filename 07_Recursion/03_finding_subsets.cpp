/*
Given a string, find all subsets of the given string
*/ 

#include <string>
#include <iostream>
using namespace std;

string findingSubsets(string str){
	if(str == "")
		return "";
	else
		return str[0]+findingSubsets(str.substr(1,str.size()-1));
}

int main(){
	string input = "abc";
	cout << findingSubsets(input) << endl;
}
