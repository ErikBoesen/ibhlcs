#pragma once
#include <vector>

using namespace std;

class MinHeap {
private:
    int leftChildIndex(int parentIndex);
    int rightChildIndex(int parentIndex);
    int parentIndex(int childIndex);
    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);
    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);

    void swap(int index1, int index2);
public:
    vector<int> items;
    int size = 0;

    int peek();
    int poll();
    void add(int item);
    void add(vector<int> items);
    void heapifyUp();
    void heapifyDown();
    vector<int> sort();
};
