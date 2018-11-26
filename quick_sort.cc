/*
 * Quick sort
 * Nov 24, 2018
 * Divide and conquer..
 */

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
  int key = arr[high];

  int pioneer = low;
  int trailer = pioneer - 1;
  while (pioneer < high) {
    if (arr[pioneer] <= key) {
      swap(arr[++trailer], arr[pioneer++]);
    } else
      ++pioneer;
  }

  swap(arr[++trailer], arr[high]);
  return trailer;
}

void quick_sort(vector<int>& arr, int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
  }
}

void print_arr(vector<int>& arr) {
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr{2037, -1, 8, 5, 8, 4, 5, 9, 6, 10, 8};
  print_arr(arr);
  quick_sort(arr, 0, arr.size() - 1);
  print_arr(arr);

  return 0;
}
