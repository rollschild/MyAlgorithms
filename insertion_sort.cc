/*
 * Insertion sort
 * Nov 23, 2018
 * Remeber, just like playing cards...
 */

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int>& arr) {
  int size = arr.size();
  for (int i = 1; i < size; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
  return;
}

void print_vec(vector<int>& arr) {
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;
}

int main() {
  vector<int> arr{2037, -1, 5, 4, 100, 4};
  print_vec(arr);
  insertion_sort(arr);
  print_vec(arr);

  return 0;
}
