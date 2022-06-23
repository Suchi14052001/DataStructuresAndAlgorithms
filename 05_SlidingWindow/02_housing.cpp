/*
Along one side of a road, there is a sequence of vacant plots of land. Areas form a sequence A[1], A[2] ... A[N]
You want to buy k acres of land to build a house. Find all segments of contiguous plots of whose sum is exactly K
Output start and end index of the subarrays

1. Brute force approach - O(N^3) - N^2 for two loops and another loop to sum them up 
   Generate all subarrays from index i to j and check if sum of elements in this window = K
   * One way to optimise this is to have a prefix sum array indicating ps(n) = ps(n-1) + a(n)
     Then you can compute sum in O(1) time. 
     
2. Another approach, say if array = [1, 3, 2, 5] Then prefix sum array = [1, 4, 6, 11]
   Now since areas are non-negative, prefix sum array will be non-decreasing sequence, can use binary search
   For every i in prefix sum array, find a j ahead of it such that pr(j) - pr(i) = K
   Overall complexity would be O(NlogN) time
   
3. Use a sliding window approach, reduces complexity to O(N) time and O(1) space
   Maintain two pointers i and j, until sum of array from i to j < K, expand window towards right
   Once it is greater, contract window from left
*/ 

#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

void housing(vector<int> areas, int sum){
	int i=0, j=0, current = 0, len=0, finali, finalj, min=INT_MAX;
	
	while((i>=0 && i<=(int)areas.size()-1) && (j>=0 && j<=(int)areas.size()-1)){
		// Perform expansion towards right
		current +=areas[j];
		j++;
		
		// Contraction towards left, remove all elements until current < sum and i < j
		while((current > sum) && (i < j)){
			current -= areas[i];
			i++;
		}
		if(current == sum){
			len = j-i; // j-1-i+1
			if(min>len){
				min = len;
				finali = i, finalj = j-1; // j-1 as we did j++ above
			}
		}
	}
	cout << "(" << finali << "," << finalj << ")\n"; // Returns the smallest window
	return;
}

int main(){
	vector<int> areas = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
	int sum = 8;
	cout << "(Start index, End index) are: " << endl;
	housing(areas, sum);
	return 0;
}
