#include <iostream>
#include <vector>
#include <list>
#include "InsertionSort.h"

using namespace std;

void Print(vector<float>& vec);

void InsertionSort(vector<float>& float_vec) {
  int size = float_vec.size();
  for(int j = 1; j < size; ++j) {
    int i = j - 1;
    float key = float_vec[j];
    while(i >= 0 && float_vec[i] > key) {
      float_vec[i + 1] = float_vec[i];
      --i;
    }
    float_vec[i + 1] = key;
  }
}

vector<float> BucketSort(vector<float>& vec) {
  int size = vec.size();
  vector<vector<float>> buckets(size);
 
  // you need to make buckets[i] an empty list
  for(auto& v : buckets) {
    v.clear();
  }

  for(auto v : vec) {
    buckets[(int)(size * v)].push_back(v);
  }

  for(auto& v : buckets) {
    // Print(v);
    InsertionSort(v);
  }

  vector<float> results;
  for(auto& v : buckets) {
    results.insert(results.end(), v.begin(), v.end());
  }

  return results;
}

void Print(vector<float>& vec) {
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  vector<float> vec{0.11, 0.88, 0, 0.006, 0.67, 0.99};
  cout << "Original array: \n";
  Print(vec);
  auto result = BucketSort(vec);
  cout << "Array after sorting: \n";
  Print(result);
  return 0;
}

