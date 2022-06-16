/*
Given a string, print all subsequences (2^N subsets) of string sorted by length and lexicographical order if the length is same

1. Using recursion + sorting. Each letter of string has two choices, it may or may not be part of subset. Sorting function should be written
   in such a way that first it will be sorted based on length, then sort it according to lexicographic order if length is same
2. Bitmasking based approach. 
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sortsubseq(string s1, string s2){
	if(s1.length() == s2.length())
		return s1 < s2;
	return s1.length() < s2.length();
}

void subsequence(string s, string o, vector<string> &res){
	// Base case
	if(s.length()==0){
		// It means that you reached leaf node
		res.push_back(o); // Result will be stored inside o
		return;
	}
	
	//Recursive case
	/*
	Isolate the first letter and make a recursive call on the remaining substring
	For that first letter, append output with this first letter once and don't append in the next case 
	*/
	char ch = s[0];
	string reduced_input = s.substr(1); // First letter will be chopped out
	subsequence(reduced_input, o + ch, res);
	subsequence(reduced_input, o, res);
}

int main(){
	string s;
	cout << "Enter the input string: \n";
	cin >> s;
	vector<string> result;
	string output = "";
	
	subsequence(s, output, result);
	// Finally we need to sort the vector
	
	sort(result.begin(), result.end(), sortsubseq);
	
	for(auto element: result)
		cout << element << endl;
	return 0;
}
