/*
Given a vector of numbers, we want to concatenate these numbers to form lexicographically largest number
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

/* This is another method that given an array of non-negative numbers, 
 * they are needed to be arranged in some order such that it gives the max number */

/*
int numDigits(int num){
	int digits = 0; 
	while (num != 0){
		num /= 10; 
		digits++; 
	}
	return digits;
}

int extendNum(int num, int n){
	string inp = to_string(num);
	string res(inp);
	int len = inp.length(), i=0;
	
	while(len!=n){
		if(i>=(int)inp.length())
			i = 0;
		res.append(1, inp[i]);
		len++; 
		i++;
	}
	return stoi(res); 
}

string concatenate(vector<int> numbers){
    string result = "";
    int max = numbers[0];
    
    // 1. Find the number of digits in largest number
    for(auto element: numbers){
		if(max < element)
			max = element;
	}
	int n = numDigits(max);
	
	// 2. Normalise all numbers - Make all numbers to have number of Digits = (n+1)
	
	// 3. Sort original numbers with respect to extended numbers
	map<int, int> sortedInput;
	for(int i=0; i<(int)numbers.size(); i++)
		sortedInput.insert({extendNum(numbers[i], n+1), numbers[i]});
	
	// 4. Combine result in reverse order
	for(auto it = sortedInput.rbegin(); it != sortedInput.rend(); it++)
		result += to_string(it->second);
    return result;
}*/

bool compConcat(string s1,string s2){
    return s1 + s2 > s2 + s1; // Descending order lo it returns
}

string concatenate(vector<int> numbers){
    vector<string> inpString;
    string res = "";

    for(int num:numbers)
        inpString.push_back(to_string(num));
    sort(inpString.begin(), inpString.end(), compConcat);

    for(string element:inpString)
        res += element;
    return res;
}

int main(){
	vector<int> input = {10, 11, 20, 30, 3};
	cout << "Lexicographically largest string: " << concatenate(input) << endl;
	return 0; 
}
