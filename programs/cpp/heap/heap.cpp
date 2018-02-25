#include <stdexcept>

#include "heap.h"

using namespace std;

int MinHeap::leftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
int MinHeap::rightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
int MinHeap::parentIndex(int childIndex) { return (childIndex - 1) / 2; }

bool MinHeap::hasLeftChild(int index) { return leftChildIndex(index) < size; }
bool MinHeap::hasRightChild(int index) { return rightChildIndex(index) < size; }
bool MinHeap::hasParent(int index) { return parentIndex(index) >= 0; }

int MinHeap::leftChild(int index) { return items[leftChildIndex(index)]; }
int MinHeap::rightChild(int index) { return items[rightChildIndex(index)]; }
int MinHeap::parent(int index) { return items[parentIndex(index)]; }

void MinHeap::swap(int index1, int index2) {
    // Better:
    // this->items[index1]=this->items[index1]+this->items[index2]-this->items[index2]=this->items[index1];
    int temp = this->items[index1];
    this->items[index1] = this->items[index2];
    this->items[index2] = temp;
}

int MinHeap::peek() {
    if (this->size == 0) throw runtime_error("No elements in heap.");
    return this->items[0];
}
int MinHeap::poll() {
    if (this->size == 0) throw runtime_error("No elements in heap.");
    int item = this->items[0];
    items[0] = items[this->size - 1];
    size--;
    heapifyDown();
    return item;
}

void MinHeap::add(int item) {
    items.push_back(item);
    this->size++;
    heapifyUp();
}
void MinHeap::add(vector<int> items) {
    for (int i = 0; i < items.size(); i++) this->add(items[i]);
}

void MinHeap::heapifyUp() {
    int index = this->size - 1;
    while (hasParent(index) && parent(index) > this->items[index]) {
        swap(parentIndex(index), index);
        index = parentIndex(index);
    }
}
void MinHeap::heapifyDown() {
    int index = 0;  // Start at root element
    while (hasLeftChild(index)) {
        int smallerChildIndex = leftChildIndex(index);
        if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
            smallerChildIndex = rightChildIndex(index);
        }

        if (this->items[index] < this->items[smallerChildIndex]) {
            break;
        } else {
            swap(index, smallerChildIndex);
        }
        index = smallerChildIndex;
    }
}

vector<int> MinHeap::sort() {
    vector<int> sorted;
    while (this->size != 0) sorted.push_back(this->poll());
    return sorted;
}
