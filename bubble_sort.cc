/*
 * Nov 23, 2018
 * Bubble sort
 */

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& arr) {
  int size = arr.size();

  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      // last i elements are already sorted and in place
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
  }

  return;
}

void print_arr(vector<int>& arr) {
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;

  return;
}

int main() {
  vector<int> arr{100, 2037, -1, 5, 4, 0};
  bubble_sort(arr);
  print_arr(arr);

  return 0;
}
