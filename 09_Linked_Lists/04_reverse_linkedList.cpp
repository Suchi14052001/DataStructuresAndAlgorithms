/*
1. Can do it recursively
   If you have a sample linked list 1->2->3->4->5, assume that you make a call on head->next, and you get the reversed result like
   1-> 2<-3<-4<-5 and smallHead which points to 5. Now, the work that you still need to do after recursive call is, head is at 1. Reverse 
   that single link. Make 
     * head->next->next = head;
       head->next = NULL;
   
   Base case is when (head->next == NULL), it means that there is only one node and it is the small head

2. Can do it iteratively
   Have two pointers current=head and prev=NULL. 
   temp = current->next;
   current->next = prev;
   prev = current;
   current = temp;
 
* Recursive functions take extra space because of stack memory. Iterative functions do not take extra space
* O(n) time and O(n) space for recursive; O(n) time and O(1) space for Iterative

3. K-Reverse
	* Reverse every K nodes. If input is 1->2->3->4->5->6->7->8->NULL and k=3, Output is 3->2->1->6->5->4->8->7->NULL 
	* Reverse smaller linked lists and connect them. In every recursive call, reverse first k nodes and make a recursive call on remaining
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

void insertInMiddle(node* &head, int data, int pos){ // After pos number of nodes, new node will be inserted
	if(pos==0 || head==NULL)
		insertAtHead(head, data);
	else{
		node* temp = head;
		// Make required number of jumps to reach the previous node to which you want to insert the new node
		for(int jump=1; jump<=pos-1; jump++)
			temp = temp -> next;
		
		node* newNode = new node(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
	return;
}

node* recReverse(node* head){
	// Base case
	if(head->next == NULL ||  head==NULL) // head==NULL case is checked such that if an empty list is passed, that case will also be handled
		return head;
		
	// Recursive case
	node* smallHead = recReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallHead;
}

void iterReverse(node* &head){
	node *current=head, *prev=NULL, *temp;
	
	while(current!=NULL){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	head = prev; // After the end of the loop prev is the head
	return;
}

node* kReverse(node* head, int k){
	// Base case
	if(head == NULL)
		return NULL;
		
	// Recursive case - reverse first k nodes
	node *current=head, *prev=NULL, *temp, *smallHead;
	int count = 1;
	
	while(current!=NULL && count<=k){
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
		count++;
	}
	
	// temp points to one next point
	if(temp != NULL){
		smallHead = kReverse(temp, k);
		head->next = smallHead;
	}
	return prev;
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
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);	
	insertInMiddle(head, 6, 5);
	head = recReverse(head);
	iterReverse(head);
	printList(head);
	head = kReverse(head, 3);
	printList(head);
	return 0;
}
