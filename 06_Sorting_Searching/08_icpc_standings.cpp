/*
For each team, compute the distance between their preferred place and their place in ranklist. Sum of these distances will be called badness
Given team names and their preferred placements, find one ranklist with minimum possible badness
*/ 

#include <vector>
#include <iostream>
using namespace std;

int badness(vector<pair<string,int>> teams){
    int res=0;
    vector<int> count((int)teams.size()+1, 0);
    
    for(int i=0; i<(int)teams.size(); i++)
		count[teams[i].second]++;
		
	int pos=1;
	for(int i=1; i<=(int)teams.size(); i++){
		while(count[i]){
			res += abs(i - pos);
			count[i]--;
			pos++;
		}
	}
	return res;
}

int main(){
	vector<pair<string, int>> teams = {{"WinOrBooze", 1}, {"BallOfDuty", 2}, {"WhoKnows", 2}, {"BholeChature", 1}, {"DCECoders", 5}, 
		{"StrangeCase", 7}, {"WhoKnows", 7}};
	cout << "Minimum badness is: " << badness(teams) << endl;
	return 0;
}
