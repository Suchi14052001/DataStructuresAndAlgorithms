#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    int key;
    unordered_set<int> s = {1,2,4,5,5,3};

    //For search operation
    cout << "Enter a key: ";
    cin >> key;
    if(s.find(key) != s.end()){
        // Means that key is present in the unordered set
        // s.end() denotes the address that is just after ending of that set 
    }

    //For erasing a particular key
    s.erase(4);

    //For inserting a key
    s.insert(11);

    return 0;
}