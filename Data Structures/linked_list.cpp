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
void reverse_linked_list_recursive(NODE **head){
	if(*head == NULL)	return;
	NODE *first, *rest;
	first = *head;
	rest = first->next;
	if(rest == NULL)	return;
	reverse_linked_list_recursive(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
	return;
}

// reverse linked list iteratively
void reverse_linked_list(NODE **head){
	NODE *curr, *prev, *next;
	curr = *head;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

// insert at any given position
void insertAtAnyPosition(NODE **head, int key, int position){
	NODE *new_node = new NODE;
	new_node->key = key;
	NODE *temp = *head;
	if(position == 0){
		new_node->next = temp;
		*head = new_node;
		return;
	}
	else{
		for(int i=1; i<position; i++){
			temp = temp->next;
		}
		if(temp->next == NULL){
			temp->next = new_node;
			return;
		}
		else{
			new_node->next = temp->next;
			temp->next = new_node;
			return;
		}
	}
}

// insert node
void insert(NODE **head, int data){
	NODE *temp = new NODE;
	temp->key = data;
	temp->next = NULL;	
	if(*head == nullptr){
		*head = temp;
		return;
	}
	NODE *p = *head;
	while(p!=NULL)
		p = p->next;
	p = temp;
	return;
}

// get value at nth index
int GetNth(NODE **head, int n){
	NODE *p = *head;
	int i;
	for(i=0; i<n && p->next!=NULL; i++)
		p = p->next;
	if(i < n)
		throw "n greater than linked list length";
	return p->key;
}

// get nth value from back
int nthFromBack(NODE *head, int n){
	int len = 0;
	NODE *p = head;
	while(p!=NULL){
		p=p->next;
		len++;
	}
	if(len-n<0) throw "length error";
	for(int i=0; i<len-n; i++)
		p = p->next;
	return p->key;
}

// get value at mid-point
int midPoint(NODE *head){
	NODE *slow = head;
	NODE *fast = head;
	while(fast!=NULL){
		fast = fast->next;
		if(fast!=NULL){
			slow=slow->next;
			fast=fast->next;
		}
	}
	return slow->key;
}

// detect a loop
bool isThereLoop(NODE *head){
	NODE *slow = head;
	NODE *fast = head;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return 1;
	}
	return 0;
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
	reverse_linked_list_recursive(&head);
	//reverse_linked_list(&head);
	print_linked_list(head);
	insertAtAnyPosition(&head, 5, 0);
	print_linked_list(head);
	insertAtAnyPosition(&head, 6, 4);
	print_linked_list(head);
	return 0;
}
