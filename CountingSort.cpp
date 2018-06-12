#include <iostream>
#include <vector>

using namespace std;

int Max(vector<int>& arr) {
  int size = arr.size();
  int largest = arr[0];
  for(int i = 1; i < size; ++i) {
    if (largest < arr[i])
      largest = arr[i];
  }
  return largest;
}

vector<int> CountingSort(vector<int>& arr) {
  int size = arr.size();
  int occur_size = Max(arr);
  vector<int> occur(occur_size + 1, 0);
  for(int i = 0; i < size; ++i) {
    ++occur[arr[i]];
  }

  for(int i = 1; i <= occur_size; ++i) {
    occur[i] += occur[i - 1];
  }

  vector<int> result(size, 0);
  for(int i = size - 1; i >=0; --i) {
    result[occur[arr[i]] - 1] = arr[i];
    --occur[arr[i]];
  }

  return result;
}

int main() {
  vector<int> arr{12, 123, 123, 32, 4, 12, 0, 8, 100};
  vector<int> result = CountingSort(arr);
  for(auto v : result) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}
