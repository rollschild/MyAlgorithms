/*
 * Merge sort..
 * Nov 24, 2018
 * Divide and conquer..
 */
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int low, int middle, int high) {
  // vector<int> left(arr.begin() + low, arr.begin() + middle + 1);
  vector<int> left{};
  // left.assign(arr.begin() + low, arr.begin() + middle + 1);
  // vector<int> right(arr.begin() + middle + 1, arr.begin() + high + 1);
  vector<int> right{};
  // right.assign(arr.begin() + middle + 1, arr.begin() + high + 1);
  for (int i = low; i <= middle; ++i) {
    left.push_back(arr[i]);
  }
  for (int j = middle + 1; j <= high; ++j) {
    right.push_back(arr[j]);
  }
  int left_pos = 0;
  int right_pos = 0;
  int pos = low;
  while (left_pos < left.size() && right_pos < right.size()) {
    if (left[left_pos] <= right[right_pos])
      arr[pos++] = left[left_pos++];
    else
      arr[pos++] = right[right_pos++];
  }

  if (left_pos < left.size()) {
    for (int i = pos; i <= high; ++i) arr[i] = left[left_pos++];
  }

  if (right_pos < right.size()) {
    for (int j = pos; j <= high; ++j) arr[j] = right[right_pos++];
  }
}

void merge_sort(vector<int>& arr, int low, int high) {
  if (low >= high) return;
  int pivot = (low + high) / 2;

  merge_sort(arr, low, pivot);
  merge_sort(arr, pivot + 1, high);
  merge(arr, low, pivot, high);
}

void print_arr(vector<int>& arr) {
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;
  return;
}

int main() {
  vector<int> arr{2037, -1, 4, 5, 4, 12, 100, 0};
  print_arr(arr);
  merge_sort(arr, 0, arr.size() - 1);
  print_arr(arr);
  return 0;
}
