#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int heap_size;

void MaxHeapify(vector<int>& vec, int index) {
  int largest = index;
  int left_child = 2 * index + 1;
  int right_child = 2 * index + 2;

  if(heap_size > left_child && vec[left_child] > vec[index]) {
    largest = left_child;
  }

  if(heap_size > right_child && vec[right_child] > vec[largest]) {
    largest = right_child;
  }

  if(largest != index) {
    swap(vec[largest], vec[index]);
    MaxHeapify(vec, largest);
  }
}

int Max(vector<int>& vec) {
  return vec[0];
}

int ExtractMax(vector<int>& vec) {
  if(heap_size < 1) {
    cout << "Error! Heap size overflow!\n";
    return INT_MIN;
  }

  int max_ele = Max(vec);
  vec[0] = vec[heap_size - 1];
  --heap_size;
  MaxHeapify(vec, 0);
  vec.pop_back();
  return max_ele;
}

int Parent(int index) {
  return (index - 1) / 2;
}

// O(logn)
void IncreaseKey(vector<int>& vec, int index, int new_value) {
  if(new_value <= vec[index]) {
    cout << "The new value is smaller than the current value!\n";
    return;
  }

  vec[index] = new_value;

  while(Parent(index) >= 0 && vec[index] > vec[Parent(index)]) {
    swap(vec[index], vec[Parent(index)]);
    index = Parent(index);
  }
}


// O(logn)
void MaxInsert(vector<int>& vec, int new_ele) {
  ++heap_size;
  // vec[heap_size - 1] = INT_MIN;
  vec.push_back(INT_MIN);
  IncreaseKey(vec, heap_size - 1, new_ele);
}

void Print(vector<int>& vec) {
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
  return;
}

int main() {
  vector<int> vec{12};
  heap_size = vec.size();
  MaxInsert(vec, 10);
  MaxInsert(vec, 8);
  MaxInsert(vec, 5);
  MaxInsert(vec, 3);
  MaxInsert(vec, 2);
  MaxInsert(vec, 1);
  MaxInsert(vec, 7);

  Print(vec);

  IncreaseKey(vec, 3, INT_MAX);

  Print(vec);

  cout << ExtractMax(vec) << endl;

  Print(vec);

  return 0;
}

