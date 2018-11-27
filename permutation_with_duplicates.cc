#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void permute_recursion(vector<int>& original, vector<int>& memo,
                       vector<bool>& used, vector<vector<int>>& res);

vector<vector<int>> permute(vector<int>& original) {
  vector<int> memo{};
  vector<vector<int>> res{};
  vector<bool> used(original.size(), false);
  if (original.size() == 0) return res;
  permute_recursion(original, memo, used, res);
  return res;
}

void permute_recursion(vector<int>& original, vector<int>& memo,
                       vector<bool>& used, vector<vector<int>>& res) {
  if (memo.size() == original.size()) {
    if (find(res.begin(), res.end(), memo) == res.end()) res.push_back(memo);
    return;
  }

  for (int i = 0; i < original.size(); ++i) {
    if (used[i]) continue;

    memo.push_back(original[i]);
    used[i] = true;
    permute_recursion(original, memo, used, res);
    used[i] = false;
    memo.pop_back();
  }
}

void print(vector<int>& vec) {
  for (auto v : vec) cout << v << " ";
  cout << endl;
}

int main() {
  vector<int> vec{3, 1, 3};
  auto res = permute(vec);

  for (auto r : res) {
    print(r);
  }
  return 0;
}
