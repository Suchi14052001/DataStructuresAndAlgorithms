/*
Given a running stream of characters, output the first non-repeating character in the string formed so far after every new character you get in
the output. Output 0 if such a character doesn't exist

1. Can use brute force approach maintaining a mapping between character and number of occurences of each and scanning from left to right each time
   This is a O(N^2) time complexity algorithm for a string of length N
   
2. Can use queue along with a hash map. Update map each time and check if front of queue has freq 1, if yes print else pop and try
   If you get empty queue print 0 at that position
   Can solve this problem in O(N) time 
*/ 

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){ // aabcbcd
	queue<char> first;
	unordered_map<char, int> freq;
	vector<char> out;
	
	for(char ch: S){
		if(freq.find(ch) == freq.end())
			freq.insert({ch, 1});
		else
			freq[ch]++;
			
		if(freq[ch]==1)
			first.push(ch);
			
		while(!first.empty() && freq[first.front()] > 1)
			first.pop();
			
		if(first.empty())
			out.push_back('0');
		else
			out.push_back(first.front());
	}
	return out;
}

int main(){
	vector<char> out = FindFirstNonRepeatingCharacter("aabcbcd");
	for(auto ch: out)
		cout << ch;
	cout << endl;
	return 0;
}
