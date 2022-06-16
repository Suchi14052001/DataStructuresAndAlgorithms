/*
Given a list of n strings, each consisting of digits and spaces, number of spaces same for each entry, Implement a variation of sort
None of the strings contain consecutive spaces, no string starts with a space or ends with it
Reversed, key (denotes which column is to be used for comparison) and type of ordering will be given in question
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int toInteger(string s);
bool lexicographicCompare(pair<string, string> s1, pair<string, string> s2);
bool numericCompare(pair<string,string> s1, pair<string,string> s2);

int toInteger(string s){
	int ans=0, p=1;
	for(int i=s.length()-1; i>=0; i--){
		ans+=((s[i]-'0')*p);
		p=p*10;
	}
	return ans;
}

bool numericCompare(pair<string,string> s1, pair<string,string> s2){
	return toInteger(s1.second) < toInteger(s2.second);
}
	
bool lexicographicCompare(pair<string, string> s1, pair<string, string> s2){
	return s1.second < s2.second;
}

int main(){
	int n,i=0; 
	cout << "Input n\n";
	cin >> n;
	// to remove the extra \n, 
	cin.get();
	vector<string> inputs;
	string input;
	cout << "Enter strings\n";
	while(i<n){
		getline(cin, input);
		inputs.push_back(input);
		i++;
	}
	
	int key;
	string reversal, order;
	cout << "Enter key, reversal and order\n";
	cin >> key;
	cin >> reversal;
	cin >> order;
	
	// 1. Extract the keys and store them as pairs (string, key)
	vector<pair<string, string>> elements;
	pair<string, string> temp;
	for(int i=0; i<n; i++){
		temp.first = inputs[i];
		int j=0;
		char *token = strtok((char*)inputs[i].c_str(), " "); 
		// strtok function accepts char array as parameter, hence we convert string into char array and typecast it
		
		while(token!=NULL){
			if(j==key-1)
				temp.second = token;
			token = strtok(NULL, " ");
			j++;
		}
		elements.push_back(temp);
	}
	
	// 2. Sort 
	if(order == "numeric")
		sort(elements.begin(), elements.end(), numericCompare);
	else
		sort(elements.begin(), elements.end(), lexicographicCompare);
	
	// 3. Reverse
	if(reversal=="true")
		reverse(elements.begin(), elements.end());
		
	// 4. Print the output
	for(int i=0; i<n; i++)
		cout << elements[i].first << endl;
	return 0;
}
