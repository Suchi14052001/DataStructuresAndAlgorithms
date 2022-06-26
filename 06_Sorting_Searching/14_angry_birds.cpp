/*
There is a long straight line containing N bird nests at positions x1, x2, .. xN. There are B number of birds (B<=N) which become angry
if you put them in same nest or closer to eachother. Assign birds to nests such that minimum distance between any two birds is as large 
as possible. What is the largest minimum distance

1. Using brute force approach, there will be nCb number of options
2. Use binary search. Say you have five stalls and three birds with nests at [1, 2, 4, 8, 9]. Create search space with respect to distance
   Minimum distance is 0 and max distance between two birds is 9-1=8. So number line will be [0, 1, 2, 3, 4, 5, 6, 7, 8]
   * Calculate mid point = 4. Can you distribute all three birds such that min distance between all birds is atleast 4?
		* Place one bird at 0, Second bird at 8 (as 8-1>=4), there's no space to place third bird
		* With min distance atleast 4, we could not place all three birds .. hence move end to mid-1
   * If you can place with some mid point, move start to mid+1
   * Time taken by this approach is O(nLog(largest difference between nests))
*/ 

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int angry_birds(int birds, int nests, vector<int> positions){
	int res = INT_MIN, start = 0, placed = 1, lastloc=0;
	int end = positions[birds-1] - positions[0];
	
	while(start<=end){
		int mid = (start+end)/2;
		placed=1; lastloc=0;
		for(int i=1; i<(int)positions.size(); i++){
			if(positions[i] - positions[lastloc] >= mid){
				placed++;
				lastloc=i;
			}
			if(placed==birds)
				break;
		}
		if(placed==birds){
			res=mid;
			start = mid+1;
		}else
			end = mid-1;
	}
	return res; 
}

int main(){
	int birds=3;
	vector<int> positions = {1, 2, 4, 8, 9};
	int nests=(int)positions.size();
	
	// We need to sort the positions vector just to be sure
	sort(positions.begin(), positions.end());
	cout << "Largest minimum distance is: " << angry_birds(birds, nests, positions) << endl;
	return 0;
}
