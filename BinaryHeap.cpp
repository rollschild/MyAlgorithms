#include <iostream>
#include <climits>

using namespace std;

void swap(int* lhs, int* rhs);
// root must be smallest node
// all nodes must be smaller than their children
// left not necessarily smaller than right
// represented as an array

class MinHeap {
 private:
  int* ptr = nullptr;
  int capacity = 0;
  int heap_size = 0;

 public:
  MinHeap(int capacity);
  void Heapify(int root);
  int parent(int node) { return (node - 1) / 2; }
  int left(int node) { return 2 * node + 1; }
  int right(int node) { return node * 2 + 2; }
  int extractMin();  // getMin then remove it
  void decreaseKey(int node, int byHowMuch);
  int getMin() { return ptr[0]; }
  void delKey(int i);
  void insertKey(int k);
};

MinHeap::MinHeap(int cap) {
  capacity = cap;
  heap_size = 0;
  ptr = new int[capacity];
}

void MinHeap::insertKey(int k) {
  if (heap_size == capacity) {
    cout << "Limit reached." << endl;
    return;
  }
  ++heap_size;
  int i = heap_size - 1;
  ptr[i] = k;
  while (i != 0 && ptr[parent(i)] > ptr[i]) {
    swap(&ptr[parent(i)], &ptr[i]);
    i = parent(i);
  }
}

void MinHeap::decreaseKey(int node, int byHowMuch) {
  if (byHowMuch <= ptr[node]) {
    ptr[node] -= byHowMuch;
  } else {
    cout << "Limit reached." << endl;
    return;
    }
    while (node != 0 && ptr[parent(node)] > ptr[node]) {
      swap(&ptr[parent(node)], &ptr[node]);
      node = parent(node);
    }
}

int MinHeap::extractMin() {
  if (heap_size == 0) {
    return INT_MAX;
  }
  if (heap_size == 1) {
    --heap_size;
    return ptr[0];
  }
  // will return root eventually, although it's already removed from the array
  int root = ptr[0];
  // to be continued.
  ptr[0] = ptr[heap_size - 1];
  --heap_size;
  Heapify(0);
  return root;
}

void MinHeap::delKey(int i) {
  decreaseKey(i, ptr[i] - INT_MIN);
  extractMin();
}

// assuming the subtrees are already heapified
void MinHeap::Heapify(int i) {
  int l = left(i);   // left child
  int r = right(i);  // right child
  int smallest = i;
  if (l < heap_size && ptr[l] < ptr[i]) {
    smallest = l;
  }
  if (r < heap_size && ptr[r] < ptr[smallest]) {
    smallest = r;
  }
  if (smallest != i) {
    swap(&ptr[smallest], &ptr[i]);
    Heapify(smallest);
  }
}

void swap(int* lhs, int* rhs) {
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int main() {
    MinHeap heap(11);
    heap.insertKey(3);
    heap.insertKey(2);
    heap.delKey(1);
    heap.insertKey(15);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(45);
    cout << heap.extractMin() << endl;
    cout << heap.getMin() << endl;
    heap.decreaseKey(2, 1);
    cout << heap.getMin() << endl;
    return 0;
}
