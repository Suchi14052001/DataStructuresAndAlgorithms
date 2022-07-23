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

bool atKthLast(node* head, int k){
	int count=1;
	while(head!=NULL && count<=k){
		head=head->next;
		count++;
	}
	
	return (head==NULL && count==k+1)?true:false;
}

int kthLastElement(node *head, int k){
    while(head!=NULL){
		if(atKthLast(head, k))
			return head->data;
		head=head->next;
	}
	return -1;
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
	
	cout << "Kth last element is: " << kthLastElement(head1, 5) << endl;
	return 0;
}

