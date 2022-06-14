/*
Given the start and finish times of activities, print the maximum number of activities
Input is stored in vector of pairs. Each pair contains start and end of activity 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int countActivites(vector<pair<int,int>> activities){
    sort(activities.begin(), activities.end());
    vector<int> start;
    int count=0, maxCount=INT_MIN, low=0;
    
    for(size_t i=0; i<activities.size(); i++)
		start.push_back(activities[i].first);
  
	for(size_t i=0; i<activities.size()-1; i++){
		count = 0, low = i;
		// Get the correct location of activities[i].second in the start array
		while(activities[i].second > start[low])
			low++;
		
		// If that position is equal to activities.size(), then count = 1
		if(low == (int)activities.size()){
			count++;
			if(maxCount<count)
				maxCount = count;
		}else{
			// Loop through and find the total count
			int current = low;
			count++;
			low = 0;
			while(current!=(int)activities.size()){
				count++;
				while(activities[current].second > start[low])
					low++;
				current = low;
			}
			if(maxCount<count)
				maxCount = count;
		}
	}
    return maxCount;
}

int main(){
	vector<pair<int,int>> arr = {{7,9}, {0,10}, {4,5}, {8,9}, {4,10}, {5,7}};
	cout << "Maximum number of activities: " << countActivites(arr) << endl;
	
	return 0;
}
