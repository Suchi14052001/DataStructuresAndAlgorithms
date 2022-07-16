/*
Given a number N and modern phone keypad. Generate all possible strings 
*/ 

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void smartKeypad(string input, string curr="", int i=0){
	if(curr.length() == input.length()){
		cout << curr << endl;
		return;
	}
	
	for(int j=0; j<(int)keypad[input[i] - '0'].size(); j++)
		smartKeypad(input, curr + keypad[input[i] - '0'][j], i+1); 
}

int main(){
	smartKeypad("23");
	return 0;
}
