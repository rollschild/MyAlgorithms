/* Nov 23, 2018
 * Counting sort..
 */

#include <iostream>
#include <vector>

#define RANGE 255

using namespace std;

vector<int> couting_sort(vector<int>& arr) {
  vector<int> result(arr.size(), 0);
  vector<int> count(RANGE + 1, 0);

  for (auto a : arr) {
    ++count[a];
  }

  for (int i = 1; i <= RANGE; ++i) {
    count[i] += count[i - 1];
    // To get cummulative position
  }

  for (auto a : arr) {
    result[count[a] - 1] = a;
    --count[a];
  }

  return result;
}

int main() {
  vector<int> arr{12, 1, 5, 4, 4, 0, 3, 9, 3, 4};
  auto re = couting_sort(arr);
  for (auto r : re) {
    cout << r << " ";
  }
  cout << endl;

  return 0;
}
