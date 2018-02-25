#include <iostream>
#include "heap.h"

using namespace std;

int main() {
    static int arr[] = {3, 1, -5, 9, 2, 599, 20};
    vector<int> X(arr, arr + sizeof(arr)/sizeof(arr[0]));
    MinHeap heap;
    heap.add(X);
    cout << "Unsorted: ";
    for (const auto& n : X) cout << n << ' '; cout << endl;
    cout << "Sorted:   ";
    for (const auto& n : heap.sort()) cout << n << ' '; cout << endl;
}
