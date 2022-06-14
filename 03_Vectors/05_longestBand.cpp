/*
Given an array of N integers, find the length of the longest band
Band is a subsequence which can be reordered in such a manner that all elements appear consecutive (with difference + or -1)

Array can be sorted and then you can traverse and find the length of longest band O(nLogn + n) time
Pick start of every band, then generate the entire chain 
*/ 

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestBand(vector<int> arr){
	int highest = 1, cont=0, incr=1, length=1;
	
	unordered_set<int> list;
	for(auto element : arr)
		list.insert(element);
	
	for(int element: list){
		// check if this element can be start of a band
		
		if(list.find(element-1) == list.end()){
			length =1;
			do{
				cont = 0;
				if(list.find(element+incr) != list.end()){
					length++;
					incr++;
					cont=1;
				}
			}while(cont==1);
			
			if(highest<length)
				highest = length;
		}
	}
	return highest;
}

int main(){
	vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6}; 
	cout << "Length of the longest band is: " << longestBand(arr) << endl;
	
	return 0;
}
