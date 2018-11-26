/*
 * Time limit exceeded for really large board input.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (word.length() == 0) return false;
    vector<vector<pair<int, int>>> dict{};
    vector<pair<int, int>> coords{};
    check(board, word, coords, dict);
    if (dict.size() == 0) return false;
    for (auto d : dict) {
      if (d.size() == word.length()) return true;
    }
    return false;
  }

  void check(vector<vector<char>>& board, string word,
             vector<pair<int, int>>& coords,
             vector<vector<pair<int, int>>>& dict) {
    if (word.length() == 0) {
      dict.push_back(coords);
      return;
    }

    pair<int, int> prev_pos;
    char w = word[0];
    vector<pair<int, int>> pos = search(board, w);
    if (pos.size() == 0) return;
    for (auto v : pos) {
      vector<pair<int, int>> tmp = coords;
      if (coords.size() == 0) {
        tmp.push_back(v);
        check(board, word.substr(1, word.length() - 1), tmp, dict);
      } else {
        prev_pos = coords.back();
        if (find(coords.begin(), coords.end(), v) == coords.end() &&
            is_adjacent(prev_pos, v)) {
          // vector<pair<int, int>> tmp = coords;
          tmp.push_back(v);
          check(board, word.substr(1, word.length() - 1), tmp, dict);
        }
      }
    }
  }

  vector<pair<int, int>> search(vector<vector<char>>& board, char letter) {
    vector<pair<int, int>> pos{};
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == letter) pos.push_back(make_pair(i, j));
      }
    }
    return pos;
  }
  bool is_adjacent(pair<int, int>& coord_one, pair<int, int>& coord_two) {
    if ((abs(coord_one.first - coord_two.first) == 1 &&
         coord_one.second == coord_two.second) ||
        (abs(coord_one.second - coord_two.second) == 1 &&
         coord_one.first == coord_two.first)) {
      return true;
    } else
      return false;
  }
};

int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };

  Solution solution;
  string s = "ABCCED";
  cout << solution.exist(board, s) << endl;
  return 0;
}
