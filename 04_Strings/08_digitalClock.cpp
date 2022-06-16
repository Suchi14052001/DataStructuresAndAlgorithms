#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string convert_to_digital_time(int minutes){
	string hr=to_string(minutes/60), min=to_string(minutes%60);
	if(min.length()==1){
		min.append(1, '0'); // First parameter denotes number of times we want to add character/string
		reverse(min.begin(), min.end());
	}
	
	return hr+":"+min;
}

int main(){
	int minutes;
	cout << "Enter the number of minutes: \n";
	cin >> minutes;
	
	cout << "Digital time is " << convert_to_digital_time(minutes) << endl;
	return 0; 
}
