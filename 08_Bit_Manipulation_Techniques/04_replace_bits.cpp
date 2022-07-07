/*
Given two 32 bit numbers N and M and two bit positions i and j
Set all bits between i and j in N equal to M
* Firstly clear bits from i to j
* Left shift M by i and do or with N and return 
*/ 

#include <iostream>
using namespace std;

void clearBitsInRange(int &n, int i, int j){
	int a =  -1 << (j+1);
	int b = (1 << i) - 1;
	int mask = a | b;
	n = n & mask;
}

void replaceBits(int &n, int m, int i, int j){
	clearBitsInRange(n, i, j);
	n = n | (m << i);
}

int main(){
	
	return 0;
}
