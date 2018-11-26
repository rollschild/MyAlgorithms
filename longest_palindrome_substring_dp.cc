class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.length() <= 1) return s;
    int len = s.length();
    vector<vector<bool>> dict(len, vector<bool>(len, false));
    string res = "";
    for (int i = s.length() - 1; i >= 0; --i) {
      for (int j = i; j < s.length(); ++j) {
        dict[i][j] = (s[j] == s[i]) && (j - i < 3 || dict[i + 1][j - 1]);
        if (dict[i][j]) {
          if (j - i + 1 > res.length()) res = s.substr(i, j - i + 1);
        }
      }
    }
    return res;
  }
};
