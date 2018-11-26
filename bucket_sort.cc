/*
 * Bucket sort
 * Nov 23, 2018
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void bucket_sort(vector<float>& float_arr) {
  int size = float_arr.size();
  vector<float> dict[size];
  for (auto fa : float_arr) {
    dict[(int)(size * fa)].push_back(fa);
  }
  for (int i = 0; i < size; ++i) {
    sort(dict[i].begin(), dict[i].end());
  }  // supposed to be insertion sort?

  int index = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < dict[i].size(); ++j) {
      float_arr[index++] = dict[i][j];
    }
  }

  return;
}

void print_arr(vector<float>& vec) {
  for (auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  vector<float> floa{0.99, 0.1, 0.19, 0.34, 0.18, 0.4, 0.5, 0.55};
  print_arr(floa);
  bucket_sort(floa);
  print_arr(floa);

  return 0;
}
