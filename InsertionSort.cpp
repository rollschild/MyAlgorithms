// Best case O(n)
// Wosrt case O(n^2)
#include <iostream>
// #include <vector>

#include "InsertionSort.h"

using namespace std;

void InsertionSort(vector<int>& vec) {
  int size = vec.size();
  for(int i = 1; i < size; ++i) {
    int key = vec[i];
    int j = i - 1;
    while(j >= 0 && vec[j] > key) {
      vec[j + 1] = vec[j];
      --j;
    }
    vec[j + 1] = key;
  }
}

int main() {
  vector<int> vec{-12, 0, 2037, 55, 6, 55};
  InsertionSort(vec);
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;

  return 0;
}

