// O(d(n+k))
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int Max(vector<int>& vec) {
  return *max_element(vec.begin(), vec.end());
}

void CountingSort(vector<int>& vec, int base, int size) {
  vector<int> result(size, 0);
  vector<int> count(10, 0);
  for(int i = 0; i < size; ++i) {
    ++count[vec[i] / (int)pow(10, base) % 10];
  }

  for(int i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }

  for(int i = size - 1; i >= 0; --i) {
    result[count[vec[i] / (int)pow(10, base) % 10] - 1] = vec[i];
    --count[vec[i] / (int)pow(10, base) % 10];
  }

  vec = result;
}

void RadixSort(vector<int>& vec, int size) {
  int max_value = Max(vec);

  int limit = 1;

  limit = (int)log10((double)max_value) + 1;
  cout << limit << endl; 
  for(int j = 0; j < limit; ++j) {
    CountingSort(vec, j, size);
  } 
}

int main() {
  int size = 0;
  cin >> size;
  vector<int> vec;
  for(int n = 0; n < size; ++n) {
    int value;
    cin >> value;
    vec.push_back(value);
  }

  RadixSort(vec, size);

  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;

  return 0;

}
