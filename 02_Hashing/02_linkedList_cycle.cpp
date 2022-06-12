// To check if a linked list contains a cycle or not using a hash table

// Storing a value will not work as multiple nodes may have the same value but there's no cycle in the Linked list
// Instead as we need unique key for each node, we can use address of each node

// Can use unordered_map<node*,bool> or unordered_set<node*>
// Traverse through the Linked list and insert each new address into the hash table, if you find a redundant address, there is a cycle

/*
bool containsCycle(node* head){
    unordered_map<node*,bool> hashtable;

    node* temp = head;
    while(temp!=NULL){
        //Check if this node is already present
        if(hashtable.count(temp) != 0)
            return true;
        hashtable[temp] = true;
        temp = temp -> next;
    }
    return false;   
}
*/

// Alternate way is to use Flyod's algorithm
// Can also do it using slow and fast pointer approach