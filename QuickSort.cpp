// Worst case O(n^2)
// Average O(nlogn)
// Sorting in-place

#include <iostream>
#include <vector>

using namespace std;

// Partition and QuickSort
int Partition(vector<int>& vec, int left, int right) {
  int i = left - 1;
  for(int j = left; j <= right - 1; ++j) {
    if (vec[j] <= vec[right]) {
      ++i;
      swap(vec[i], vec[j]);
    }
  }
  swap(vec[i + 1], vec[right]);
  return i + 1;
}

void QuickSort(vector<int>& vec, int left, int right) {
  if (left < right) {
    int pivot = Partition(vec, left, right);
    QuickSort(vec, left, pivot - 1);
    QuickSort(vec, pivot + 1, right);
  }
}

int main() {
  vector<int> vec{12, 23, -100, 6, 69, 49, 49, 49, 12, 2037, -8};
  QuickSort(vec, 0, vec.size() - 1);
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}
