#include <iostream>
#include <string>
using namespace std;

int main(){
	/* A. Initialisation of strings */
	
		// 1. One way to represent is using character array - not recommended as it is not very flexible
		char s[100] = {'g', 'o', 'o', 'd', '\0'};
		
		// 2. Inbuilt string class uses dynamic arrays - size can be changed even during the runtime
		string s1 = "Sucharitha is a goog girl";
		string s2("Sucharitha");
		
		// 3. Input can be taken from user. By default, it assumes that string will be terminated by \n
		string s3;
		getline(cin, s3);
		
		// 4. To accept a paragraph terminated by a '.' (by a specific delimiter)
		string s4;
		getline(cin, s4, '.');
	
	/* B. To iterate a string. These strings are automatically null terminated */
		for(char ch : s4)
			cout << ch;
		cout << endl;
		
	/* C. To search for a word inside a string */
		int index = s1.find("good"); 
		
		// find function returns the largest unsigned long value if required word is not found. This is equal to -1 in signed integer
		if(index == -1)
			cout << "Not found\n"; 
			
		// To find the second occurence of the word in given string
		index = s1.find("good", index+1); // This means start search from (index+1)
	
	return 0;
}
