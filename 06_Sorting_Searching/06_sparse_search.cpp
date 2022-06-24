/*
Given a sorted array of strings that is interspersed with empty strings, write a method to find the location of a given string

1. Can do linear search. Takes O(N*W) time where N is number of words and W is length of string
2. Can use modified binary search, if the mid element is "", then traverse in both directions and relocate to nearest non empty string
   In worst case, this will take O(N) but in average case it performs better than linear search
*/ 

#include <iostream>
#include <cstring>
using namespace std;

int sparseSearch(string words[], string search, int start, int end){
	int mid=-1;
	if(start>end)
		return 0;
	
	mid = (start+end)/2;
	if(words[mid] == ""){
		int i=mid-1, j=mid+1;
		while(words[i] == "" && i>=start)
			i--;
		while(words[j] == "" && j<=end)
			j++;
		mid = (abs(j-mid)<abs(mid-i))?j:i;
	}
	
	// Binary search logic
	if(words[mid] == search)
		return mid;
	else if(words[mid] > search)
		return sparseSearch(words, search, start, mid-1);
	else
		return sparseSearch(words, search, mid+1, end);
}

int main(){
	string words[] = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""};
	string search = "dog";
	int start = 0, end = (sizeof(words)/sizeof(words[0]))-1;
	
	cout << "Location of " << search << " is: " << sparseSearch(words, search, start, end)+1 << endl;
}
