/*
Alien is N steps above you. You are at ground 0. You can take jumps in power of 2. Return minimum number of steps possible to reach

If n = 7 (111), find nearest power of 2 to it, which is 100
* This will be the first step, repeat the same for 111 - 100 and continue until convergence 
*/ 

#include <iostream>
#include <cmath>
using namespace std;

int earthLevel(int k){
	int digits, sum = 0, step = 0, copyk = k, nearestPower;
	while(sum != copyk){
		digits =  floor(log2(k)) + 1;
		nearestPower = k & (1 << (digits-1));
		sum += nearestPower;
		step++; 
		k -= nearestPower;
	}
	return step;
}

int main(){
	int n = 7;
	cout << "Number of steps are: " << earthLevel(n) << endl;
	return 0;
}
