#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Demo
    vector<int> arr = {1,2,3,5};
    cout << "Number if elements in arr: " << arr.size() << endl;
    cout << "Capacity of arr: " << arr.capacity() << endl;

    // To create copy of arr, you can use vector<int> arrCopy(arr);    
    return 0;
}