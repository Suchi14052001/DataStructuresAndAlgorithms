/*
Given a ladder containing n steps, you can take a jump of 1, 2, or 3 at each step. Find the number of ways to climb the ladder
* f(N) = f(N-1) + f(N-2) + f(N-3)
* Base case is when N=0 or N=1

Eg: If number of steps is 4, then total number of ways = 7
				  4 
		3         2           1
    2   1   0   1   0         0    
   1 0  0       0                 
   0

* Using dynamic programming, overlapping subproblems can be avoided (Computing same states can be avoided) 
* As we are making 1, 3, 3^2, ... calls each time, time complexity is O(3^N)
*/ 

#include <iostream>
using namespace std;

int countWays(int steps){
	if(steps < 0)
		return 0; /* This is done inorder to handle cases when steps become negative (to handle invalid state; 
		If steps=2, f(steps-3) leads to invalid state) */
	
	if(steps == 0)
		return 1;
	else
		return countWays(steps-1) + countWays(steps-2) + countWays(steps-3);
}

int main(){
	int steps = 5;
	cout << "Number of ways to reach " << steps << " steps is: " << countWays(steps) << endl;
	return 0;
}
