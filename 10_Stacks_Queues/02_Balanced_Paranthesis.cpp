#include <iostream>
#include <string>
#include <stack>
using namespace std;

char closeBracket(char ch){
	if(ch=='(')
		return ')';
	else if(ch=='{')
		return '}';
	else if(ch=='[')
		return ']';
	return '0';
}

bool isBalanced(string s){
	stack<char> brackets;
	
	for(char ch: s){
		switch(ch){
			case '(':
			case '{':
			case '[': 
				brackets.push(ch);
				break;
			
			case ')':
			case '}':
			case ']':
				if(!brackets.empty() && closeBracket(brackets.top()) == ch)
					brackets.pop();
				else
					return false;
				break;
			
			default:
				continue;
		}
	}
	if(brackets.empty())
		return true;
	return false;
}

int main(){
	string s = "((a+b+c)+[d])[";
	if(isBalanced(s))
		cout << s << " has Balanced Paranthesis" << endl;
	else
		cout << s << " does not have Balanced Paranthesis" << endl;
	return 0;
}
