// Merge takes time O(n)
// Whole algorithm, worse case O(log(n))
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void Merge(vector<int>& vec, int p, int q, int r) {
  int len_1 = q - p + 1;
  int len_2 = r - q;
  vector<int> lhs(len_1 + 1, 0);
  vector<int> rhs(len_2 + 1, 0);
  for(int i = 0; i < len_1; ++i) {
    lhs[i] = vec[i + p];
  }
  for(int j = 0; j < len_2; ++j) {
    rhs[j] = vec[j + q + 1];
  }

  lhs[len_1] = INT_MAX;
  rhs[len_2] = INT_MAX;

  int i = 0;
  int j = 0;

  for(int k = p; k <= r; ++k) {
    if (lhs[i] < rhs[j]) {
      vec[k] = lhs[i];
      ++i;
    }
    else {
      vec[k] = rhs[j];
      ++j;
    }
  }
}

void MergeSort(vector<int>& vec, int p, int r) {
  // It's very important to check if p < r!!!
  if (p < r) {
    int q = (p + r) / 2;
    // 0 to q; q+1 to r
    MergeSort(vec, p, q);
    MergeSort(vec, q + 1, r);
    Merge(vec, p, q, r);
  }
}

void Print(vector<int>& vec) {
  for(auto v : vec) {
    cout << v << " ";
  }
  cout << endl;
}

int main() {
  vector<int> vec{2037, -100, 0, 999, 12, 66, 5, 999};
  cout << "Pre-MergeSort: " << endl;
  Print(vec);
  MergeSort(vec, 0, vec.size() - 1);
  cout << "Post-MergeSort: " << endl;
  Print(vec);
  return 0;
}
