#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtPosition function below.

/*
struct SinglyLinkedListNode{
    int data;
    SinglyLinkedListNode* next;
};
*/

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
  SinglyLinkedListNode *new_node =
      (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));
  new_node->data = data;
  SinglyLinkedListNode *temp = head;
  if (position == 0) {
    new_node->next = temp;
    head = new_node;
    return head;
    } 
    else{
        for (int i = 1; i < position; i++) {
            temp = temp->next;
        }
        if(temp->next == NULL){
            temp->next = new_node;
            return head;
        }
        else{
            new_node->next = temp->next;
            temp->next = new_node;
            return head;
        }
    }
}

int main()
