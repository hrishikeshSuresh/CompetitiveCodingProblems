#include<bits/stdc++.h>
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node *curr = head;
    unordered_map<Node*, int> cycle_list;
    while(curr != NULL){
        cycle_list[curr]++;
        if(cycle_list[curr] > 1)
            return true;
        curr = curr->next;
    }
    return false;
}
