#include <iostream>
#include <vector>

using namespace std;

void PrintVec(vector< vector<int> >& vec) {
  for (auto v : vec) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
  cout << endl;
}

vector<int> ParseToVec(int arr[], int size) {
  vector<int> vec{};
  for (int i = 0; i < size; ++i) {
    vec.push_back(arr[i]);
  }
  return vec;
}

vector< vector<int> > results{};

void HeapPermutate(int arr[], int size, int n) {
  vector<int> element{};

  if (n == 1) {
    element = ParseToVec(arr, size);
    results.push_back(element);
    return;
  }

  for (int i = 0; i < n; ++i) {
    HeapPermutate(arr, size, n - 1);
    if (size % 2 == 0) {
      swap(arr[i], arr[n - 1]);
    } else {
      swap(arr[0], arr[n - 1]);
    }
  }

}


int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  HeapPermutate(arr, size, size);
  PrintVec(results);
  cout << results.size() << endl;
  return 0;
}
