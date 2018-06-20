// O(nlogn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MaxHeapify(vector<int>& vec, int heap_size, int index) {
  int largest = index;
  int left_child = index * 2 + 1;
  int right_child = index * 2 + 2;

  if((heap_size > left_child) && (vec[index] < vec[left_child])) {
    largest = left_child;
  }
  if((heap_size > right_child) && (vec[largest] < vec[right_child])) {
    largest = right_child;
  }

  if(largest != index) {
    swap(vec[index], vec[largest]);
    MaxHeapify(vec, heap_size, largest);
  }
}

void BuildMaxHeap(vector<int>& vec) {
  int vec_size = vec.size();
  int heap_size = vec_size;
  for(int i = vec_size / 2 - 1; i >= 0; --i) {
    MaxHeapify(vec, heap_size, i);
  }
}

void PrintVector(vector<int>& vec) {
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

void HeapSort(vector<int>& vec) {
  int heap_size = vec.size();
  BuildMaxHeap(vec);
  for(int j = vec.size() - 1; j >= 1; --j) {
    swap(vec[j], vec[0]);
    MaxHeapify(vec, --heap_size, 0);
  }
}

int main() {
  vector<int> vec{12, -3, 0, 100, 93, -12222, 5, 23, 15, 14, 13, 12};

  HeapSort(vec);
  PrintVector(vec);
  
  return 0;
}
