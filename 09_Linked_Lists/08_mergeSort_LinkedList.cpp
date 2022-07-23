/*
Analysis of complexities of Merge sort for Array vs Linked list
* For array, calculating mid point takes O(1) time; For Linked lists, calculating mid point takes O(N) time
* To sort array of size N, it takes 2T(N/2); Same for linked lists as well
* Merging of array takes O(N) time; Same for linked lists as well

O(NlogN) time overall for both
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

node* midPoint(node* head){
	node* slow = head, *fast = head->next;
	
	while(fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
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

node* mergeSort(node* head){
	// Base case - If linked list has zero or one elements
	if(head==NULL or head->next==NULL)
		return head;
	
	// Recursive case - Find midpoint, do recursive sorting and merge
	node* mid = midPoint(head);
	
	node* leftHead = head, *rightHead = mid->next;
	mid->next = NULL; // Link at mid will be broken as a result we get smaller linked lists
	
	leftHead = mergeSort(leftHead);
	rightHead = mergeSort(rightHead);
	
	return merge(leftHead, rightHead); // To merge sorted linked lists whose head is pointed to leftHead and rightHead respectively
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
	node* head = NULL;
	insertAtHead(head, 16);
	insertAtHead(head, 4);
	insertAtHead(head, 10);
	insertAtHead(head, 1);
	insertAtHead(head, 6);	
	printList(head);
	
	head = mergeSort(head);
	printList(head);
	return 0;
}
