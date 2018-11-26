/* Exceeds time limit for realllllyyyy lonnnnggggg word arrays */

class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res{};
    if (board.size() == 0) return res;
    if (words.size() == 0) return res;
    int row_upper = board.size();
    int col_upper = board[0].size();
    int size = words.size();
    int word_index = 0;
    bool word_exist = false;

    while (word_index < size) {
      string word = words[word_index];
      int len = word.length();
      word_exist = false;
      for (int i = 0; i < row_upper; ++i) {
        if (word_exist) break;
        for (int j = 0; j < col_upper; ++j) {
          if (dfs(board, i, j, row_upper, col_upper, word, 0, len)) {
            word_exist = true;
            if (find(res.begin(), res.end(), word) == res.end())
              res.push_back(word);
            break;
          }
        }
      }
      ++word_index;
    }
    return res;
  }

  bool dfs(vector<vector<char>>& board, int row, int col, int row_upper,
           int col_upper, string word, int pos, int len) {
    if (pos == len) return true;
    if (row < 0 || row >= row_upper || col < 0 || col >= col_upper)
      return false;
    char c = word[pos];
    if (board[row][col] != c) return false;
    board[row][col] = '*';
    bool check =
        dfs(board, row + 1, col, row_upper, col_upper, word, pos + 1, len) ||
        dfs(board, row, col + 1, row_upper, col_upper, word, pos + 1, len) ||
        dfs(board, row - 1, col, row_upper, col_upper, word, pos + 1, len) ||
        dfs(board, row, col - 1, row_upper, col_upper, word, pos + 1, len);

    board[row][col] = c;

    return check;
  }
};
