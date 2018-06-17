// INEFFICIENT
// Worst case O(n^2)
#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& vec) {
  int size = vec.size();

  for(int i = 0; i < size - 1; ++i) {
    for(int j = size - 1; j > i; --j) {
      if (vec[i] > vec[j]) {
        swap(vec[i], vec[j]);
      }
    }
  }
}

void Print(vector<int>& vec) {
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec{2037, 12, 999, 8, 0, -6, 100, -99, 234, -6};
  cout << "Pre-BubbleSort: " << endl;
  Print(vec);
  BubbleSort(vec);
  cout << "Post-BubbleSort: " << endl;
  Print(vec);

  return 0;
}
