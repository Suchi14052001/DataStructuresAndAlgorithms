#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> menu;
    string item;

    // To add a new item
    menu["maggi"] = 15;
    menu["idli"] = 10;

    // To know if an element is there in a hashtable or not. count() returns 0 or 1
    cout << "Enter a key: ";
    cin >> item;
    if(menu.count(item) == 0)
        cout << item << " is not available\n";
    else
        cout << "Cost: " << menu[item] << endl;
    
    // To remove an item from the hashtable
    menu.erase("idli");

    // To iterate over entire hashtable
    for(pair<string, int> item: menu)
        cout << item.first << ": " << item.second << endl; // This is called as a foreach loop. For this we take O(N) time

    return 0;
}