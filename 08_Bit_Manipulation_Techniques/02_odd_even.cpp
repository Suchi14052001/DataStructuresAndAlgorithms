/*
Function to check if a number is odd or even
* For odd numbers, last bit is one; Else zero
* Perform and with 1, If we get 1, then original number is odd else even
*/ 

#include <iostream>
using namespace std;

int main(){
	int x;
	cout << "Enter an integer: ";
	cin >> x;
	
	if(x&1)
		cout << "odd" << endl;
	else
		cout << "even" << endl;
	return 0;
}
