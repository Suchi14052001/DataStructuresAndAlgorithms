/*
Time Complexity = Space Complexity = O(N+M) where N is number of nodes in first Linked list, M is number of nodes in second Linked list
* Space Complexity is due to recursion else it is O(1) memory
*/

#include <iostream>
using namespace std;

class node{
public: // To make it available to other helper functions
	int data;
	node* next;
	
	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

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

node* merge(node* a, node* b){
	if(a==NULL)
		return b;
		
	if(b==NULL)
		return a;
		
	// Temporary head pointer created in every function call is c
	node* c;
	if(a-> data < b->data){
		c = a;
		c->next = merge(a->next, b);
	}
	else{
		c = b;
		c->next = merge(a, b->next); 
	}
	return c;
}

void printList(node* head){
	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
	return;
}

int main(){
	node* head1 = NULL;
	insertAtHead(head1, 5);
	insertAtHead(head1, 4);
	insertAtHead(head1, 3);
	insertAtHead(head1, 2);
	insertAtHead(head1, 1);	
	
	node* head2 = NULL;
	insertAtHead(head2, 8);
	insertAtHead(head2, 7);
	insertAtHead(head2, 6);	
	
	printList(merge(head1, head2));
	return 0;
}
