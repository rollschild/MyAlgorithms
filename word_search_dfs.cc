#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0) return false;
    int row_upper = board.size();
    int col_upper = board[0].size();
    int word_len = word.length();
    if (word_len == 0) return false;
    for (int i = 0; i < row_upper; ++i) {
      for (int j = 0; j < col_upper; ++j) {
        if (dfs(board, i, j, word, 0, row_upper, col_upper, word_len))
          return true;
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, int board_row, int board_col,
           string& word, int word_pos, int row_upper, int col_upper,
           int word_len) {
    if (word_pos == word_len) return true;
    if (board_row < 0 || board_col < 0 || board_row >= row_upper ||
        board_col >= col_upper)
      return false;
    char c = board[board_row][board_col];

    if (c != word[word_pos]) return false;

    board[board_row][board_col] = '*';
    bool check = dfs(board, board_row - 1, board_col, word, word_pos + 1,
                     row_upper, col_upper, word_len) ||
                 dfs(board, board_row, board_col - 1, word, word_pos + 1,
                     row_upper, col_upper, word_len) ||
                 dfs(board, board_row + 1, board_col, word, word_pos + 1,
                     row_upper, col_upper, word_len) ||
                 dfs(board, board_row, board_col + 1, word, word_pos + 1,
                     row_upper, col_upper, word_len);

    board[board_row][board_col] = c;
    return check;
  }
};
int main() {
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'},
  };

  Solution solution;
  string s = "ABCB";
  cout << solution.exist(board, s) << endl;
  return 0;
}
