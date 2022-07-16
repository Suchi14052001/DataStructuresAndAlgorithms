/*
Oswald and Henry
N coins [C1, c2,... Cn] with values of [V1, V2, ... Vn]
Player can either pick first coin or last coin of the row
Return Maximum possible value Oswald can earn if he plays first
k is the number of times each player can pickup coins in one chance
*/ 

#include <iostream>
#include <vector>
using namespace std;

int score=0;

void oswaldCount(int n, vector<int> v, int start, int end, int k){
	// Base case - When there are one or two elements
	if(start>end)
		return;
			
	// Recursive case - Oswald Can pick first or last element in first turn. Henry can pick first or last element in next turn 
	for(int i=0; i<k; i++){
		if(end-start>=0){
			if(v[start]>v[end]){
				score += v[start];
				start++;
			}
			else{
				score+=v[end];
				end--;
			}	
		}
	}
	
	for(int i=0; i<k; i++){
		if(end-start>=0){
			if(v[start]>v[end])
				start++;
			else
				end--;
		}
	}
	oswaldCount(n, v, start, end, k);
}

int MaxValue(int n, vector<int> v, int k){
	score=0;
	oswaldCount(n,v,0,n-1,k);
	return score;
}

int main(){
	int n=5;
	vector<int> values = {1,2,3,4,5};
	
	cout << "Oswald's score is: " << MaxValue(n, values, 3) << endl;
	return 0;
}

