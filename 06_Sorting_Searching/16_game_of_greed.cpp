/*
Number of friends = k
Array of N coins, at each index i you have coin of value a[i]
Divide the coins among a group of k friends, such that you maximise the least coins you get
  * Think about the search space in such cases. Here, range of coins we can get is the search space
For example {1,2,3,4} 
* My search space would be {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
* Use binary search and check if you are able to partition the coins array and give each of the friends atleast arr[mid] coins
* If not, reduce end to mid-1, if yes increase start to mid+1 
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int getCoins(vector<int> arr, int k){
	vector<int> copy(arr);
	sort(copy.begin(), copy.end());
	
	int start=copy[0], end=0, res=INT_MIN;
	for(int i:arr)
		end+=i;
	
	while(start<=end){
		int mid = (start+end)/2, temp=0, partitions=0;
		for(int i=0; i<(int)arr.size();){
			while(temp<mid){
				temp +=arr[i];
				i++;
			}
			if(i-1<=(int)arr.size()-1){
				partitions++;
				temp=0;
			}
			if(partitions==k)
				break;
		}
		if(partitions==k){
			res = mid;
			start = mid + 1;
		}else
			end = mid - 1;
	}
	return res;
}

int main(){
	int friends=3; 
	vector<int> coins = {10, 22, 40, 50};
	cout << "Maximum of the minimal coins I can get is: " << getCoins(coins, friends) << endl;
}
