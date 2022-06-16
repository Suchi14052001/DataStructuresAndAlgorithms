/*
Given a palindromic string, replace exactly one character with any lowercase english letter so that
resulting string is not a palindrome and that is the lexicographically smallest one possible

Return resulting string or return empty string if it is not possible
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool checkPalindrome(string str){
	string rev = str; 
	reverse(rev.begin(), rev.end());
	return str == rev;
}

string breakPalindrome(string palindrome) {
	string result = "";
	int changed=0;
	for(char ch='a'; ch<='z'; ch++){
		changed=0; result="";
		for(int i=0; i<(int)palindrome.length(); i++){
			if(i==((int)palindrome.length()/2) && ((int)palindrome.length()%2)!=0){
				result+=palindrome[i];
				continue;
			}
			if(ch < palindrome[i] && changed==0){
				result+=ch;
				changed=1;
			}else
				result+=palindrome[i];
		}
		if(changed==0 && palindrome.length()!=1)
			result[palindrome.length()-1] = ch;
		if(checkPalindrome(result)==0)
			return result;
	}
	if(result.length()==1)
		return "";
}

int main(){
	string input = "aba";
	cout << "Resulting palindrome is: " << breakPalindrome(input) << endl;
}
