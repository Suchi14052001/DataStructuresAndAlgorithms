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
	printList(head);
	return 0;
}
