// Eventually will exceed time limit
class Solution {
 public:
  int longestValidParentheses(string s) {
    if (s.length() <= 1) return 0;
    int len = s.length();
    int max_len = 0;
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        dp[i][j] = (dp[i + 1][j - 1] && s[i] == '(' && s[j] == ')') ||
                   check(s.substr(i, j - i + 1));
        if (dp[i][j]) {
          if (j - i + 1 > max_len) max_len = j - i + 1;
        }
      }
    }
    return max_len;
  }

  bool check(const string& str) {
    if (str.length() <= 1) return false;

    stack<char> storage{};
    int len = str.length();
    for (int i = 0; i < len; ++i) {
      if (str[i] == '(')
        storage.push(str[i]);
      else {
        if (storage.empty()) return false;
        if (storage.top() != '(') return false;
        storage.pop();
      }
    }

    return storage.empty();
  }
};
