/*
Given a string, replace all the spaces in the string with %20

1. Whenever you find a space, add %20 and shift the remaining by 2 places. Inefficient as it takes quadratic time
2. In one pass, calculate number of spaces. Say 5. Total chars = 5*3 = 15. But 5 characters for spaces are already present. Hence 
   additional characters = 15-5 = 10. Start from right and shift each character by 10 places.
*/

#include <iostream>
#include <cstring>
using namespace std;

void space20(char *s){
	int spaces = 0;
	
	for(int i=0; s[i]!='\0'; i++){
		if(s[i] == ' ')
			spaces++;
	}
	
	int shift = spaces*3 - spaces;
	int finalIndex = strlen(s) + shift; // This should be marked as termination for new string
	s[finalIndex] = '\0';
	
	for(int i = strlen(s)-1; i>=0; i--){
		if(s[i] == ' '){
			s[finalIndex-1] = '0', s[finalIndex-2] = '2', s[finalIndex-3] = '%';
			finalIndex -= 3;
		}
		else{
			s[finalIndex-1] = s[i];
			finalIndex--;
		}
	}
}

int main(){
	char input[100];
	cout << "Enter your input\n";
	cin.getline(input, 100);
	space20(input);
	// Since character array is passed by reference, all changes will be seen here. It need not be returned from function
	cout << input << endl;
	return 0;
}
