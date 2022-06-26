/*
Given an integer N and an integer P, find square root of N upto P places 
1. Square root of ten lies in [0,10] interval, this will be the monotonic search space. if arr[mid]^2<=N, then store this mid and search in the
   right. Else if it is greater, search in the left part. After the loop, you will get the integral part of square root in log N time
   * If you do a linear search like while(i^2 < N) i++; it will take root of N time. 
   To find the fractional part upto P places, you can use linear search
*/ 

#include <iostream>
#include <math.h>
using namespace std;

float square_root(int n, int p){
	float res=0;
	int start=0, end=n;
	
	while(start<=end){
		int mid=(start+end)/2;
		if(mid*mid == n)
			return mid;
		else if(mid*mid < n){
			res=mid;
			start=mid+1;
		}else
			end=mid-1;
	}
	int dec=1;
	while(dec<=p){
		while(res*res <= n)
			res += pow(10, -dec);
		res -= pow(10, -dec);
		dec++;
	}
	return res;
}

int main(){
	int n=10, p=4;
	cout << "Square root of " << n << " upto " << p << " decimal places is: " << square_root(n,p) << endl;
}
