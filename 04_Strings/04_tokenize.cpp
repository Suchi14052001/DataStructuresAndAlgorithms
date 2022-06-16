/*
Can be done using (a) stringstream class (b) strtok function (c) Custom tokenize function
*/

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

char* mystrtok(char* str, char delim);

char* mystrtok(char* str, char delim){
	// A static variable is maintained to know the state of input variable
	static char* input = NULL;
	
	// Input str is the whole input string in the first call and NULL in subsequent calls
	if(str!=NULL)
		input = str;
		
	if(input == NULL)
		return NULL;
	
	// If you use static arrays, they cannot be returned as they get destroyed. Hence dynamic array is used
	static char *token = new char[strlen(input)+1];
	int i=0;
	for(; input[i]!='\0'; i++){
		if(input[i] != delim)
			token[i] = input[i];
		else{
			// You need to put a null character at the end and return it as a token
			token[i] = '\0';
			input = input + i + 1; // Bring the input pointer to the next location
			return token;
		}
	}
	
	// For the last token, since input[i]=='\0' meets, it wont go inside the loop, hence this should be kept manually for last token
	token[i] = '\0';
	input = NULL;
	return token;
}

int main(){
	/* TOKENIZE USING STRINGSTREAM CLASS */
		string input;
		cout << "Enter your input: \n";
		getline(cin, input);
		
		stringstream buffer(input);
		// This supports left shift and right shift operators - can be used to read and write data into buffer
		
		string token;
		vector<string> tokens;
		while(getline(buffer, token, ' ')){
			tokens.push_back(token);
		}
		
		for(auto element:tokens)
			cout << element << endl;

	/* TOKENIZE USING STRTOK FUNCTION - works on character arrays */ 
		char input1[100];
		cout << "Enter your input: \n";
		cin.getline(input1, 100);
		
		/* The way this works is, it starts from starting of input and returns one token each time
		   Hence to get all tokens, pass the string for first time and NULL in subsequent calls
		   When no more tokens are available this returns NULL - can be used as exit condition 
		   
		   This function internally maintains the state of the string in the last function call by using a static variable 
		*/
		
		char* token1 = strtok(input1, " ");
		while(token1 != NULL){
			cout << token1 << endl;
			token1 = strtok(NULL, " ");
		}
		 
		 
	/* CUSTOM STRING TOKENIZER */
		char input2[100];
		cout << "Enter your input\n";
		cin.getline(input2, 100);
		token1 = mystrtok(input2, ' ');
		
		while(token1 != NULL){
			cout << token1 << endl;
			token1 = mystrtok(NULL, ' ');
		}
	
	return 0;
}
