/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
  if (s.length <= 1) return 0;

  let dp = new Array(s.length);
  dp.fill(0);
  let max_len = 0;
  for (let i = 1; i < s.length; i++) {
    if (s[i] === ')') {
      if (s[i - 1] == '(') {
        dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
      } else {
        if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(') {
          dp[i] =
            (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) +
            dp[i - 1] +
            2;
        }
      }
    }
    max_len = Math.max(max_len, dp[i]);
  }
  return max_len;
};
