/*
Given price of stock for next n days, calculate span of stock's price for all n days

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) 
for which the price of the stock was less than or equal to today's price
* Given [100, 80, 60, 70, 60, 75, 85], stock spans would be [1, 1, 1, 2, 1, 4, 6]
*/ 

#include <iostream>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> v) {
    vector<int> res;
    int count =0;
    for(int i=0; i<(int)v.size(); i++){
		count = 0;
		for(int j=i; j>=0; j--){
			if(v[j] <= v[i])
				count ++;
			else
				break;
		}
		res.push_back(count);
	}
	return res;
}

int main(){
	vector<int> v = {100, 80, 60, 70, 60, 75, 85};
	vector<int> res = stockSpan(v);
	
	for(auto element: res)
		cout << element << " ";
	cout << endl;
	return 0;
}
