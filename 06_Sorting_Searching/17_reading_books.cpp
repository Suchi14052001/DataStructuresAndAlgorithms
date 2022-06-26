/*
Given number of pages in n different books and m students 
Books are arranged in any order of number of pages
* Every student is assigned to read some consecutive segment of books
* Task is to assign books in such a way that max num of pages assigned to a student is minimum
*/ 

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minPages(vector<int> books, int m){
	int start=0, end=0, res=INT_MAX;
	for(int i:books)
		end+=i;
	
	while(start<=end){
		int mid = (start+end)/2, tempSum=0, studentsRequired=1;
		for(int i=0; i<(int)books.size(); i++){
			if(books[i] > mid){
				studentsRequired = m + 1;
				break;
			}
			if(tempSum + books[i] > mid){
				tempSum = books[i];
				studentsRequired++;
			}else
				tempSum+=books[i];
		}
		if(studentsRequired>m)
			start = mid + 1;
		else{
			res = mid;
			end = mid - 1;
		}
	}
	return res;
}

int main(){
	int students = 2;
	vector<int> books = {10, 20, 30, 15};
	cout << "Minimum number of pages assigned is: " << minPages(books, students) << endl;
	return 0;
}
