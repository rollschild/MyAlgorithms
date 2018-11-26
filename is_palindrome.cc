/*
 * check if an integer is a palindrome
 *
 */
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x == 0) return true;
    if (x < 0) return false;

    string s = to_string(x);
    for (int i = 0; i < s.length() / 2; ++i) {
      if (s[i] != s[s.length() - 1 - i]) return false;
    }

    return true;
  }
};
