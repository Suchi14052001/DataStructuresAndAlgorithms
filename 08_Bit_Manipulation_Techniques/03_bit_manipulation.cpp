/*
1. get ith bit
2. set ith bit
3. clear ith bit
* Numbering of bits is done from right, starting from 0
*/ 

#include <iostream>
using namespace std;

int getIthBit(int n, int i){
	// Simply left shift 1 by i and perform and with this & n
	// Then if this value > 0, then that bit is one; else that bit is zero
	// 1 << i will be called as the mask
	
	return ((n & (1 << i))>0);
}

void setIthBit(int &n, int i){
	n = n | (1 << i);
} 

void clearIthBit(int &n, int i){
	//        1 1 0 1
	// Mask = 1 0 1 1 if i = 2
	// n & ~(1 << i)
	n = n & ~(1 << i);
}

void updateIthBit(int &n, int i, int v){
	// firstly clearIthBit
	// If v=1, take one at the position and do or ; Else take 0 and do or
	int mask; 
	clearIthBit(n, i);
	mask = v << i;
	n = n | mask;
}

void clearLastIBits(int &n, int i){
	// If i=5, clear bits from 0-4
	// Perform left shift of -1 by i; then & with n
	n = n & (-1 << i);
}

int main(){
	int n=5, i=2;
	cout << i << "th bit of " << n << " is: " << getIthBit(n, i) << endl;
	return 0;
}
