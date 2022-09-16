/*
Given a string of balanced expression, return true if it contains redundant paranthesis else false
Set of paranthesis are redundant if same sub-expression is surrounded by multiple brackets or unnecessary brackets

* Use a stack, push operands and operators also this time
* When you get a closing bracket, pop the stack until opening bracket and maintain a bool variable to see if you got across any operator in between or not
*/ 

#include <iostream>
#include <string>
#include <stack>
using namespace std;

char openBracket(char ch){
	if(ch==')')
		return '(';
	else if(ch=='}')
		return '{';
	else if(ch==']')
		return '[';
	return '0';
}

bool isOperator(char ch){
	return (ch=='+' || ch=='-' || ch=='*' || ch=='/')?true:false;
}

bool isRedundant(string s){
	stack<char> brackets;
	bool foundOperator = false;
	
	for(char ch: s){
		foundOperator = false;
		switch(ch){
			case ')':
			case '}':
			case ']':
				while(!brackets.empty() && brackets.top()!=openBracket(ch)){
					if(isOperator(brackets.top()))
						foundOperator = true;
					brackets.pop();
				}
				brackets.pop();
				if(!foundOperator)
					return true;
				break;
			
			default:
				brackets.push(ch);
				break;
		}
	}
	return false;
}

int main(){
	string s = "(a+(b))";
	if(isRedundant(s))
		cout << s << " has redundant paranthesis" << endl;
	else
		cout << s << " does not have redundant paranthesis" << endl;
	return 0;
}
