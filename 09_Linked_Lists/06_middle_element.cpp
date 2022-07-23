// Apply runner technique mentioned in 01_intro.txt in this folder

#include <iostream>
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

int getMid(node *head){
	node *fast = head, *slow = head;
	int mid;
	while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	mid = slow->data;
	return mid;
}

int main(){
	node* head1 = NULL;
	insertAtHead(head1, 8);
	insertAtHead(head1, 7);
	insertAtHead(head1, 6);
	insertAtHead(head1, 5);
	insertAtHead(head1, 4);
	insertAtHead(head1, 3);
	insertAtHead(head1, 2);
	insertAtHead(head1, 1);	
	
	cout << "Middle element is: " << getMid(head1) << endl;
	return 0;
}
