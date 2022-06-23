/*
Given two strings, one big string and one small string
find smallest window in big string that contains all characters of small string

1. Maintain a frequency map for the small string and also a hashmap for our window
   Expand the window until it has all the letters, then start contracting and check
*/

#include <unordered_map>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

string stringWindow(string big, string small){
	int count=0, start=0, min=INT_MAX, finali=-1;
	
	// Frequency map of small string
	unordered_map<char, int> fm;	
	for(int i=0; i<(int)small.length(); i++){
		if(fm.count(small[i]) == 0)
			fm[small[i]] = 1;
		else
			fm[small[i]]++;
	}
	
	// Our window
	unordered_map<char, int> window;
	for(int i=0; i<(int)big.length(); i++){
		
		// Expand the window
		char ch = big[i];
		if(window.count(ch) == 0)
			window[ch] = 1;
		else
			window[ch]++;
			
		// Count number of matched characters
		if(fm[ch]!=0 && window[ch]<=fm[ch])
			count++;
			
		// Check if count is equal to small.length
		if(count==(int)small.length()){
			
			// Contract from left 
			while(fm[big[start]]==0 || window[big[start]] > fm[big[start]]){
				window[big[start]]--;
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
		return "No window found\n";
	return big.substr(finali, min);
}

int main(){
	string big = "aabcbcdbb", small="bb";
	cout << "String window is: " << stringWindow(big, small) << endl;
	return 0;
}
