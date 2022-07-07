#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int n){
	int i = 1, bin = 0;
	
	while(n>0){
		bin += i*(n%2);
		n /= 2;
		i*=10;
	}
	return bin;
}

int main(){
	int n = 13;
	cout << "Binary representation of " << n << " is: " << decimalToBinary(n) << endl;
	return 0;
}
