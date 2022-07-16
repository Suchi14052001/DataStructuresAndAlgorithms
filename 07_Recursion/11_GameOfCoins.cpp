/*
Oswald and Henry
N coins [C1, c2,... Cn] with values of [V1, V2, ... Vn]
Player can either pick first coin or last coin of the row
Return Maximum possible value Oswald can earn if he plays first
*/ 

#include <iostream>
#include <vector>
using namespace std;

int oswaldCount(int n, vector<int> v, int start, int end){
	
	// Base case - When there are one or two elements
	if(start==end || start==end-1)
		return max(v[start], v[end]);
		
	if(start>end)
		return 0;
	
	// Recursive case - Oswald Can pick first or last element in first turn. Henry can pick first or last element in next turn 
	int copyStart = start, copyEnd = end;
	if(v[start+1] > v[end])
		start+=2;
	else{
		start+=1;
		end-=1;
	}
	int oswaldFirst = v[copyStart] + oswaldCount(n, v, start, end);
	
	start = copyStart, end = copyEnd;
	if(v[start] > v[end-1]){
		start+=1;
		end-=1;
	}
	else
		end-=2;
	int oswaldLast = v[copyEnd] + oswaldCount(n, v, start, end);
	
	return max(oswaldFirst, oswaldLast);
}

int MaxValue(int n, vector<int> v){
	return oswaldCount(n, v,0,n-1);
}

int main(){
	int n=4;
	vector<int> values = {1,2,3,4};
	
	cout << "Oswald's score is: " << MaxValue(n, values) << endl;
	return 0;
}
