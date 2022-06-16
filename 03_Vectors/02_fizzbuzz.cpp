/*
Problem: Return a vector<string> with numbers from 1 to n
for multiples of 3 -> store Fizz instead of number
for multiples of 5 -> store Buzz instead of number
for multiples of both 3 & 5 -> store FizzBuzz
*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<string> fizzbuzz(int n){
    vector<string> result;
    
    for(int i=1; i<=n;i++){
        if(i%3==0 && i%5==0){
            result.push_back("FizzBuzz");
        }else if(i%3==0){
            result.push_back("Fizz");
        }else if(i%5==0){
            result.push_back("Buzz");
        }else{
            result.push_back(to_string(i));
        }
    }

    return result;   
}

int main(){
    vector<string> result = fizzbuzz(6);
    for(auto element: result)
        cout << element << endl;
}