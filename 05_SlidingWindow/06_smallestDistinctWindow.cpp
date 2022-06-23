/*
Given a string, find the smallest window which contains all distinct characters of given input string
Eg: aabcbcdbcaaad 
Output: dbca
*/ 

#include <unordered_map>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

string smallestWindow(string str){
	int count=0, start=0, min=INT_MAX, finali=-1;
	
	// Calculate frequency map of string
	unordered_map<char, bool> fm;	
	for(int i=0; i<(int)str.length(); i++)
		fm[str[i]] = false;
	
	// Our window
	unordered_map<char, int> window;
	for(int i=0; i<(int)str.length(); i++){
		
		// Expand the window
		char ch = str[i];
		if(window.count(ch) == 0)
			window[ch] = 1;
		else
			window[ch]++;
			
		// Count number of matched characters
		if(!fm[ch]){
			count++;
			fm[ch] = true;
		}
			
		// Check if count is equal to small.length
		if(count==(int)fm.size()){
			
			// Contract from left 
			while(window[str[start]]>1){
				window[str[start]]--;
				start++;
			}
			
			// Note the minimum window size
			if(min > (i-start+1)){
				min = i-start+1;
				finali = start;
			}
		}
	}
	
	// Return output	
	if(finali==-1)
		return "";
	return str.substr(finali, min);
}

int main(){
	string str = "aaaa";
	cout << "Smallest distinct window is: " << smallestWindow(str) << endl;
	return 0;
}
