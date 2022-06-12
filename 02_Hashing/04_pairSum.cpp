/*
Given an array, you need to find all pairs whose sum is equal to k
Four approaches
1. Brute force approach - Take each element in outer loop and iterate through elements in front to find element (k - current element)
   This takes O(n^2)
2. Sort the array and use two pointer approach. If sum of two pointers < k, then increment left pointer. If sum = k, then increment left pointer
   and reduce right pointer. Takes O(nLogn) 
3. Can do sorting and binary search. Iterate through outer loop and find for required element in front. Takes O(nLogn)
4. Use hashing as you go. Takes O(n)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void pairsum(vector<int> arr, int sum){
    unordered_set<int> hashset;
    
    for(auto a: arr){
        int diff = sum - a;
        if(hashset.find(diff) != hashset.end()){
            // Complementary element is present 
            cout << a << "," << diff << endl;
        }
        hashset.insert(a);
    }
    // Reason for this logic working is that at a particular location, we are only looking for elements that are encountered earlier
    // This helps in avoiding repetition and invalid pairs
}

int main(){
    vector<int> arr = {-2, 3, 4, 5, 6, 2, 1, 8};
    int sum = 9;
    pairsum(arr, sum);
}
