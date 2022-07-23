/* 
 * There is an algorithm - Floyd's Cycle detection algorithm
 * Can implement using slow and fast pointer. If there is a cycle, slow becomes equal to fast at some point
 */ 

#include <iostream>
#include <unordered_set>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

bool containsCycle(node *head){
    unordered_set<node*> addresses;
    
    while(1){
		if(head == NULL)
			break;
		
		if(addresses.find(head) != addresses.end())
			return true;
			
		addresses.insert(head);
		head = head->next;
	}
    return false;
}

void insertAtHead(node* &head, int data){ // Passing address by reference
	if(head==NULL)
		head = new node(data);
	else{
		node* temp = new node(data);
		temp -> next = head;
		head = temp;
	}
	return;
}

int main(){
	node* head = new node(1);
	node* temp1 = new node(2);
	head->next = temp1;
	node* temp2 = new node(3);
	temp1->next = temp2;
	node* temp3 = new node(4);
	temp2->next = temp3;
	temp3->next = temp1;

	cout << containsCycle(head) << endl;
	return 0;
}
