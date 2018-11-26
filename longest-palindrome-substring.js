/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
  if (s.length === 0) return '';
  if (s.length === 1) return s;

  let len = s.length;
  let dp = new Array(len);
  for (let i = 0; i < len; i++) {
    dp[i] = new Array(len);
  }

  let str = '';
  for (let j = len - 1; j >= 0; j--) {
    for (let m = j; m < len; m++) {
      dp[j][m] = s[m] === s[j] && (m - j < 3 || dp[j + 1][m - 1]);
      if (dp[j][m]) {
        if (m - j + 1 > str.length) {
          str = s.slice(j, m + 1);
        }
      }
    }
  }

  return str;
};
