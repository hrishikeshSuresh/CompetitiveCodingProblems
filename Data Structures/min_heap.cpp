#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

class MinHeap{
    int *harr; // pointer to array elements
    int heap_size;
    int capacity;
public:
    MinHeap(int);
    void MinHeapify(int); // heapify sub tree at given index
    int parent(int); // find parent of given index
    int left(int); // find left child of binary sub-tree
    int right(int); // find right child of binary sub-tree
    int extractMin(); // remove minimum element, i.e., root element
    void decreaseKey(int, int); // remove element at i and replace with a lower specified character
    int getMin(); // get minimum character
    void deleteKey(int i); // remove element at i
    void insertKey(int i, int key); // add element at index i with key 
};

MinHeap::MinHeap(int cap){
    harr = new int[cap];
    capacity = cap;
    heap_size = 0;
}

int MinHeap::parent(int i){
    return (i-1)/2;
}

int MinHeap::left(int i){
    return (2*i+1);
}

int MinHeap::right(int i){
    return (2*i+2);
}

// return loawest element 
int MinHeap::extractMin(){
    if(heap_size <= 0)
        return INT_MAX;
    else if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    // remove lowest value and swap it with last element
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size && harr[l] < harr[i])
        smallest = l;
    if(r<heap_size && harr[r] < harr[smallest])
        smallest = r;
}

int main() {
    return 0;
}

