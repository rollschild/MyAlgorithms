/*
 * Radix sor..
 * Nov 24, 2018
 * Be aware of the STABLE pitfall!!!
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int>& arr);

void counting_sort(vector<int>& arr, int exp) {
  int size = arr.size();
  vector<int> output(size, 0);
  vector<int> count(10, 0);

  for (auto a : arr) {
    ++count[(a / exp) % 10];
  }

  for (int i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }

  for (auto itr = arr.rbegin(); itr != arr.rend(); ++itr) {
    output[count[(*itr / exp) % 10] - 1] = *itr;
    --count[(*itr / exp) % 10];
  }

  /*
  for (int j = 0; j < size; ++j) {
    arr[j] = output[j];
  }
  */
  arr = output;
  print_arr(arr);
}

void radix_sort(vector<int>& arr) {
  // use counting sort as sub-algorithm
  int greatest = *max_element(arr.begin(), arr.end());
  cout << greatest << endl;
  for (int exp = 1; greatest / exp > 0; exp *= 10) {
    counting_sort(arr, exp);
  }
}

void print_arr(vector<int>& arr) {
  for (auto a : arr) {
    cout << a << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec{170, 45, 75, 90, 802, 24, 2, 66};
  print_arr(vec);
  radix_sort(vec);
  print_arr(vec);
  return 0;
}
