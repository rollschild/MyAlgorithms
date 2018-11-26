// Binary Min Heap
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
 public:
  MinHeap(int cap);
  void increase(int key, int by_how_much);
  void decrease(int key, int by_how_much);
  void delete_key(int key);
  void heapify(int pos);
  void insert(int key);
  int parent(int pos) { return (pos - 1) / 2; };
  int left_child(int pos) { return pos * 2 + 1; };
  int right_child(int pos) { return pos * 2 + 2; };
  int extract_min_key();
  int get_min();
  void print();
  int locate(int key);

 private:
  int* ptr_ = nullptr;
  int capacity_ = 0;
  int heap_size_ = 0;
};

void swap(int* left, int* right) {
  int tmp = *left;
  *left = *right;
  *right = tmp;
  return;
}

MinHeap::MinHeap(int cap) {
  capacity_ = cap;
  heap_size_ = 0;
  ptr_ = new int[cap];
}

int MinHeap::locate(int key) {
  if (heap_size_ <= 0) return -1;
  int counter = 0;
  while (counter < heap_size_ && ptr_[counter] != key) ++counter;
  if (counter == heap_size_)
    return -1;
  else
    return counter;
}

void MinHeap::heapify(int pos) {
  // if (pos >= heap_size_) return;
  while (pos < heap_size_) {
    int left = left_child(pos);
    int right = right_child(pos);
    int smallest = ptr_[pos];
    if (left < heap_size_ && ptr_[left] < smallest) {
      smallest = ptr_[left];
      swap(ptr_[pos], ptr_[left]);
    }
    if (right < heap_size_ && ptr_[right] < smallest) {
      smallest = ptr_[right];
      swap(ptr_[pos], ptr_[right]);
    }
    ++pos;
  }
  return;
}

int MinHeap::extract_min_key() {
  if (ptr_ == nullptr) {
    cout << "Empty.." << endl;
    return INT_MIN;
  }
  int min_val = ptr_[0];
  ptr_[0] = ptr_[heap_size_ - 1];
  // delete (ptr_ + heap_size_ - 1);
  --heap_size_;
  heapify(0);
  return min_val;
}

void MinHeap::increase(int key, int by_how_much) {
  if (key + by_how_much > INT_MAX) {
    cout << "Max limit exceeded!" << endl;
    return;
  }

  int counter = locate(key);
  if (counter == -1) {
    cout << "Key does not exist.." << endl;
    return;
  }
  ptr_[counter] += by_how_much;
  heapify(counter);
  return;
}

void MinHeap::insert(int key) {
  if (heap_size_ == capacity_) {
    cout << "Heap is full!" << endl;
    return;
  }

  ++heap_size_;
  int pos = heap_size_ - 1;
  // ptr_[pos] = key;
  *(ptr_ + pos) = key;
  cout << "inserted!" << endl;
  while (pos > 0 && parent(pos) >= 0) {
    if (ptr_[pos] < ptr_[parent(pos)]) {
      swap(ptr_[pos], ptr_[parent(pos)]);
    }

    pos = parent(pos);
  }
  return;
}

int MinHeap::get_min() {
  if (heap_size_ <= 0) {
    cout << "Empyty.." << endl;
    return INT_MIN;
  }

  return ptr_[0];
}

void MinHeap::decrease(int key, int by_how_much) {
  if (key - by_how_much < INT_MIN) {
    cout << "Min limit exceeded!" << endl;
    return;
  }

  int counter = locate(key);
  if (counter == -1) {
    cout << "Key " << key << " does not exist.." << endl;
    return;
  }
  *(ptr_ + counter) -= by_how_much;

  while (counter > 0 && parent(counter) >= 0) {
    if (ptr_[counter] < ptr_[parent(counter)]) {
      swap(ptr_[counter], ptr_[parent(counter)]);
    }
    counter = parent(counter);
  }

  return;
}

void MinHeap::delete_key(int key) {
  if (locate(key) == -1) {
    cout << "Key does not exist.." << endl;
    return;
  }
  decrease(key, key - INT_MIN);
  extract_min_key();
  return;
}

void MinHeap::print() {
  // vector<int> values{};
  for (int i = 0; i < heap_size_; ++i) {
    cout << ptr_[i] << " ";
  }
  cout << endl;
  return;
}

int main() {
  MinHeap heap(11);

  heap.insert(3);
  heap.insert(2);
  heap.delete_key(1);
  heap.insert(15);
  heap.insert(5);
  heap.insert(4);
  heap.insert(45);
  heap.insert(1);
  heap.print();
  cout << heap.extract_min_key() << endl;
  cout << heap.get_min() << endl;
  heap.decrease(2, 1);
  cout << heap.get_min() << endl;
  heap.delete_key(2);
  heap.print();
  cout << heap.extract_min_key() << endl;
  cout << heap.get_min() << endl;
  return 0;
}
