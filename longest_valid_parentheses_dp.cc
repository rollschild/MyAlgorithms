class Solution {
 public:
  int longestValidParentheses(string s) {
    if (s.length() <= 1) return 0;
    int len = s.length();
    vector<int> dp(len, 0);
    int max_len = 0;
    for (int i = 1; i < len; ++i) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
        } else {
          // s[i - 1] = ')'
          if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(') {
            dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) +
                    dp[i - 1] + 2;
          }
        }
      }  // else dp[i] = dp[i - 1];
      max_len = max(max_len, dp[i]);
    }
    return max_len;
  }
};
