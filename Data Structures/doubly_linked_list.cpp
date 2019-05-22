#include<bits/stdc++.h>

using namespace std;

struct NODE{
	int key;
	struct NODE *prev, *next;
};

// create node
// you can also use 'new'
NODE *create_dll_node(int key){
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	new_node->key = key;
	new_node->next = new_node->prev = NULL;
	cout << "Element added to the end of the list" << endl;
	return new_node;
}

void dll_append(NODE **head, int data){
	NODE *temp = *head;
	NODE *new_node = create_dll_node(data);
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_node;
	new_node->prev = temp;
	cout << "Element added to the end of the list" << endl;
	return;
}

void dll_print(NODE *head){
	NODE *temp;
	temp = head;
	cout << "Elements in the doubly linked list" << endl;
	while(temp != NULL){
		cout << temp->key << " ";
		temp = temp->next;
	}
	cout << endl;
	return;
}

void dll_pop_back(NODE **head){
	NODE *temp = *head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	NODE *to_be_deleted = temp->next;
	to_be_deleted->prev = NULL;
	free(to_be_deleted);
	temp->next = NULL;
	cout << "Last element deleted" << endl;
}

int main(int argc, const char *argv[]){
	NODE *head = create_dll_node(1);
	dll_append(&head, 2);
	dll_append(&head, 3);
	dll_print(head);
	dll_pop_back(&head);
	dll_print(head);
	return 0;
}
