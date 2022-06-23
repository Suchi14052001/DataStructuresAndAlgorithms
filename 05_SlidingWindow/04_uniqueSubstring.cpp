/*
Given a string, find largest substring with unique characters

1. Set i=j=0. Expand j until you dont get a repeating character. Maintain a hash map to store char, last occurence of it
   <char, int>
*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

void uniqueSubString(string str){
	unordered_map<char, int> lookup; // int stores the index of last occurence of that char
	int i=0, j=0, len=1, maxLen=INT_MIN, finali;
	lookup[str[0]] = 0;
	
	for(j=1; j<(int)str.length(); j++){
		if(lookup.count(str[j]) == 0){
			// Expand the window
			lookup[str[j]] = j;
			len++;
		}
		else if(lookup.count(str[j]) && lookup[str[j]]>=i){
			if(maxLen <= len){
				maxLen = len;
				finali = i;
			}
			i = lookup[str[j]]+1;
			len = j-i+1;
			lookup[str[j]] = j;
		}
		else{
			lookup[str[j]] = j;
			len++;
		}
	}
	if(maxLen <= len){
		maxLen = len;
		finali = i;
	}
	
	cout << str.substr(finali, maxLen) << endl;
	return;
}

int main(){
	string str = "prateekbhaiya";
	uniqueSubString(str);
	return 0;
}
