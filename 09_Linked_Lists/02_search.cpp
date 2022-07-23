/*
Check whether the given key is present inside a linked list or not - If yes, return true
*/ 

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

bool isPresent(node * head, int key){
	node* temp = head;
	while(temp!=NULL){
		if(temp->data == key)
			return true;
		temp = temp->next;
	}
	return false; 
}
