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
	new_node->next = NULL;
	new_node->prev = NULL;
	cout << "Element created" << endl;
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
	cout << "DLL : ";
	while(temp != NULL){
		cout << temp->key << " ";
		temp = temp->next;
	}
	cout << endl;
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

void dll_insert_sorted_order(NODE **head, int key){
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	new_node->key = key;
	new_node->next = NULL;
	new_node->prev = NULL;
	NODE *temp = *head;
	if(temp->key > key){
		new_node->next = temp;
		temp->prev = new_node;
		*head = new_node;
		cout << "Elements added in sorted order at the beginning of DLL, " << key << endl;
		return;
	}
	while(temp->key < key && temp->next!=NULL){
		cout << "iterating " << temp->key << endl;
		temp = temp->next;
	}
	if(temp->next == NULL){
		cout << "check " << temp->key << endl;
		if(temp->key < new_node->key){
			temp->next = new_node;
			new_node->prev = temp;
			new_node->next = NULL;
			cout << "Elements added in sorted order at the end of DLL " << key << endl;
			return;
		}
		else{
			new_node->next = temp;
			(temp->prev)->next = new_node;
			new_node->prev = temp->prev;
			cout << "Elements added in sorted order at the end of DLL " << key << endl;
			return;
		}
	}
	cout << "adding " << temp->key << endl; 
	new_node->next = temp;
	(temp->prev)->next = new_node;
	new_node->prev = temp->prev;
	temp->prev = new_node;
	cout << "Elements added in sorted order" << endl;
	return;
}

void dll_reverse(NODE **head){
	NODE *curr, *temp = NULL;
	curr = *head;
	while(curr!=NULL){
		cout << curr->key << endl;
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if(temp != NULL)
		*head = temp->prev;
	cout << "Reversing DLL" << endl;
}

int main(int argc, const char *argv[]){
	NODE *head = create_dll_node(1);
	dll_print(head);	
	dll_insert_sorted_order(&head, 3);
	dll_print(head);	
	dll_insert_sorted_order(&head, 4);
	dll_print(head);	
	dll_insert_sorted_order(&head, 10);
	dll_print(head);	
	dll_insert_sorted_order(&head, 5);
	dll_print(head);
	dll_insert_sorted_order(&head, 2);
	dll_print(head);
	dll_pop_back(&head);
	dll_print(head);
	dll_reverse(&head);
	dll_print(head);	
	return 0;
}
