/*
Given two non-empty arrays of integers, find pair of numbers whose absolute difference is closest to zero
*/

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <climits>
using namespace std;

pair<int,int> minDifference(vector<int> a,vector<int> b){
    pair<int,int> result;
    sort(a.begin(), a.end());
    int low=0, minDifference=INT_MAX;
    
    for(int element: b){
		low = 0;
		while(element>=a[low] && (low>=0 && low<=(int)a.size()-1))
			low++;
		
		if(low==0 || low==(int)a.size()-1){
			int current = abs(element-a[low]);
			if(minDifference>current){
				minDifference = current;
				result.first = a[low];
				result.second = element;
			}
		}else{
			int current = abs(element-a[low-1]);
			if (min(current, abs(element-a[low]))==current){
				if(minDifference>current){
					minDifference = current;
					result.first = a[low-1];
					result.second = element;
				}
			}else{
				current = abs(element-a[low]);
				if(minDifference>current){
					minDifference = current;
					result.first = a[low];
					result.second = element;
				}
			}
		}
	}
	return result;
}

int main(){
	vector<int> a1 = {23, 5, 10, 17, 30};
	vector<int> a2 = {26, 134, 135, 14, 19};
	cout << "Minimum Difference is: (" << minDifference(a1, a2).first << ", " << minDifference(a1, a2).second << ")\n";
	return 0;
}
