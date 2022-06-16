/*
 Return list of all occurences of a given substring inside a big string. Return empty vector if it is not present.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> stringSearch(string big,string small){
    vector<int> result = {};
	int index=-1;

	do{
		index = big.find(small, index+1);
		if(index != -1)
			result.push_back(index);	
	}while(index!=-1);
	
	return result;
}

int main(){
	string bigString = "I liked the movie, acting in movie was great!";
	string smallString = "movie";
	
	for(int i: stringSearch(bigString, smallString))
		cout << i << " ";
	cout << endl;
}
