/*
Given two numbers a and b, compute (a^b) modulo 1000000007
*/

#include <iostream>
using namespace std;

long long int powerModulo(int a, int b){
	// Base case
	if(b==1)
		return a;
	
	if(b==0)
		return 1;
	
	// Recursive case
	if(b%2 == 0)
		return (powerModulo(a, b/2) * powerModulo(a, b/2))%1000000007;
	else
		return (powerModulo(a, b/2) * powerModulo(a, (b/2)+1))%1000000007;
}

int main(){
	int a=5, b=3;
	cout << a << " to the power of " << b << " is: " << powerModulo(a, b) << endl;
	return 0;
}
