/*
Function to perform string compression using count of repeated characters
Eg: aaaabcccccaaa = a4b1c5a3
If the compressed string would not become smaller than original string, return input string
*/ 

#include <string>
#include <iostream>
using namespace std;

string compressString(const string &str){   
    string result = "";
    char current=str[0];
    int count=1;
    for(int i=1; i<(int)str.length(); i++){
		if(str[i] == current){
			count ++;
			current = str[i];
		}else{
			result += current;
			result += to_string(count);
			count = 1;
			current = str[i];
		}
	}
	// Add current and final for final time
	result += current;
	result += to_string(count);
	
	// Compare lengths and return
	if(result.length() > str.length())
		return str;
	return result;
}

int main(){
	string input;
	cout << "Enter input string: " << endl;
	cin >> input;
	
	cout << "Compressed string: " << compressString(input) << endl;
	return 0; 
}
