/*
Count the number of set bits
* We know how to check if the last bit is one, put in loop and shift right
* Number of set bits will be atmost logN
*/ 

#include <iostream>
using namespace std;

int countSetBits(int n){
	int res = 0;
	while(n>0){
		res += (n&1);
		n = n >> 1;
	}
	return res;
}

int countSetBitsHack(int n){
	int res = 0;
	// Faster method
	
	while(n>0){
		n = n & (n-1); // Removes last set bit from current number
		res++;
	}
	return res;
}

int main(){
	
	return 0;
}
