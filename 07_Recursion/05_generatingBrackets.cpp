/*
Write a function to generate all possible n pairs of balanced paranthesis 
* If n = 2, there are two ways, ()() and (())

If n = 2, you have string of length n*2
Place either a ( or ) at each location but there are two conditions
* num of close brackets < num of open brackets => Only then you can place a closing bracket
* num of open brackets < n => Only then place a opening bracket
*/ 

#include <string>
#include <iostream>
using namespace std;

void generatingBrackets(int n, int open=0, int close=0, string curr=""){
	if((int)curr.length() == n*2){
		cout << curr << endl;
		return;
	}
	
	if(open < n)
		generatingBrackets(n, open+1, close, curr + "(");
	
	if(close < open)
		generatingBrackets(n, open, close+1, curr + ")");
}

int main(){
	generatingBrackets(3);
}
