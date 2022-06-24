/*
Given an array consisting of red (0), blue (1), green(2) balls. Arrange them in sorted order (Red followed by Blue then Green)
*/ 

#include <vector>
#include <iostream>
using namespace std;

vector<int> sortBalls(vector<int> balls){
    int r=0, g=0, b=0;
    for(int i:balls){
		if(i==0)
			r++;
		else if(i==1)
			b++;
		else
			g++;
	}
	
	int i=0;
	while(r>0){
		balls[i] = 0;
		r--;
		i++;
	}
	
	while(b>0){
		balls[i] = 1;
		b--;
		i++;
	}
	
	while(g>0){
		balls[i] = 2;
		g--;
		i++;
	}
    return balls;
}

int main(){
	vector<int> input = {0, 0, 1, 2, 0, 1, 2, 0};
	vector<int> result = sortBalls(input);
	
	for(int i:result)
		cout << i << " ";
	cout << endl;
	return 0;
}
