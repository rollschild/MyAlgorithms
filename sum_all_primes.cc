#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int sum(int num) {
  vector<bool> vec(num+1);
  fill_n(vec.begin(), 2, false);
  fill_n(vec.begin() + 2, num - 1, true);
  int ele = 2;
  while (ele <= num) {
    if (!vec[ele]) {
      ++ele;
      continue;
    }
    for (int i = 0; i <= num; ++i) {
      int product = ele * (ele + i);
      if (product <= num)
        vec[product] = false;
      else break;
    }
    ++ele;
  }
  int sum = 0;
  for (int j = 2; j <= num; ++j) {
    if (vec[j]) sum += j;
  }
  return sum;
}

int main() {
  cout << sum(9) << endl;
  return 0;
}
