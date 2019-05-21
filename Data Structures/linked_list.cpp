#include<bits/stdc++.h>

using namespace std;

struct NODE{
	int key;
	struct NODE *next;
};


// create node
// you can also use 'new'
NODE *create_node(int key){
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	new_node->key = key;
	new_node->next = NULL;
	cout << "Element added to the end of the list" << endl;
	return new_node;
}

// adding node to end of linked list
void append(NODE **head, NODE *new_node){
	NODE *temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	cout << "Element added to the end of the list" << endl;
	return;
}

// print linked list
void print_linked_list(NODE *head){
	cout << "Elements of linked list" << endl;
	while(head->next!=NULL){
		cout << head->key << " ";
		head = head->next;
	}
	cout << head->key << endl;
}

// deleting node
void pop_back(NODE **head){
	NODE *temp = *head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp->next = NULL;
	cout << "Popped element from the end of the list" << endl;
}

// reverse a node
void reverse_linked_list(NODE **head){
	if(*head == NULL)	return;
	NODE *first, *rest;
	first = *head;
	rest = first->next;
	if(rest == NULL)	return;
	reverse_linked_list(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
	return;
}


int main(int argc, const char *argv[]){
	NODE *head = create_node(1);
	append(&head, create_node(2));
	append(&head, create_node(3));
	print_linked_list(head);
	pop_back(&head);
	print_linked_list(head);
	append(&head, create_node(4));
	print_linked_list(head);
	reverse_linked_list(&head);
	print_linked_list(head);
	return 0;
}
