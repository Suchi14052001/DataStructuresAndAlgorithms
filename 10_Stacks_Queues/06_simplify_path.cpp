/*
Take a non-empty string representing valid Unix shell path as input and return a simplified version

cd ~/Desktop means cd home/Desktop
*/ 

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

string simplifyPath(string path){
	// 1. Find all the tokens (separated by a '/') and remove those which are not necessary
	istringstream iss(path);
	vector<string> tokens;
	string token;
	
	while(getline(iss, token, '/')){
		if(token=="" or token==".")
			continue;
		tokens.push_back(token);
	}
	
	// 2. Handling ..
	vector<string> stack;
	
	if(path[0] == '/')
		stack.push_back(""); // To handle absolute and relative paths differently
	
	for(string token: tokens){
		if(token == ".."){
			// If the stack size is zero or if the previous token is also a .. then push this token 
			if(stack.size()==0 or stack[stack.size()-1]=="..")
				stack.push_back(token);
			else if(stack[stack.size()-1] != "") // This condition is needed for absolute path
				stack.pop_back();
		}
		else
			stack.push_back(token);
	}
	
	// 3. Combine all the elements of the stack and return the output
	ostringstream oss;
	for(auto token: stack){
		if(token == "")
			oss << "/";
		else
			oss << token << "/";
	}		
	return (oss.str().length()==1)?oss.str():(oss.str().substr(0, oss.str().length()-1));
}

int main(){
	string path = "/../x/y/../z/././w/a///../../c/./"; // Output should be /x/z/c
	cout << "Simplified path of " << path << " is: " << simplifyPath(path) << endl;
	return 0;
}
