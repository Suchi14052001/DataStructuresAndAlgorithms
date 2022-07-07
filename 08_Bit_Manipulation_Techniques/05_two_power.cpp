/*
For power of 2, say 16 = 1 0 0 0 0
                    15 = 0 1 1 1 1
If a number is a power of 2, then and with (n-1) returns 0 
*/ 

#include <iostream>
using namespace std;

bool isTwoPower(int n){
	return ((n & (n-1))==0)?1:0;
}

int main(){
	int n = 16;
	cout << isTwoPower(n) << endl;
	return 0;
}
