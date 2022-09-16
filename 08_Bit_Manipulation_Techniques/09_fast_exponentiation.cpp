/*
If exponentiation is done in linear manner directly, it takes O(N) time. We try to do it using O(logN) time
  * Any number N will have atmost (logN+1) bits 
  * If you want to compute 3^5, then 3^101 in binary. Iterate through the set bits from right to left and multiply them by
    a^4 a^2 a^1 ... Then It becomes (1*a^1)*(1*a^4) = which becomes a^5 = 3^5
*/ 

#include <iostream>
using namespace std;

int fastExpo(int a, int n){ // For calculating a^n
	int ans = 1;
	while(n>0){
		int lastBit = n&1;
		if(lastBit)
			ans = ans * a;
		a = a*a;
		n = n >> 1;
	}
	return ans;
}

int main(){
	cout << "3^5 is: " << fastExpo(3, 5) << endl;
	return 0;
}
