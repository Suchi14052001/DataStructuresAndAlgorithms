/*
Given a sentence with words separated by spaces, write a sentence that returns copy of this sentence where all words
start with a capital letter and remaining are lower case
*/ 

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string normalize(const string &sentence) {
    string copy = sentence;
    transform(copy.begin(), copy.end(), copy.begin(), ::tolower); // Convert entire string to lower case first
    int index=-1;
    
    for(int i=0; i<(int)sentence.length(); ){
		while(copy[(int)i]== ' '){
			index=i;
			i++;
		}
		if((int)i==index+1)
			copy[i] = (char)(copy[i] - 32);
		i++;
	}
	
	if(copy[0]>=97 && copy[0]<=122)
		copy[0] = (char)(copy[0] - 32);
    return copy;
}

int main(){
	string s = "This is SO MUCH FUN!";
	cout << "Normalised input is: " << normalize(s) << endl;
	return 0; 
}
