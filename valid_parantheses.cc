class Solution {
 public:
  bool isValid(string s) {
    if (s.length() == 0) return true;
    stack<char> storage{};
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
        storage.push(s[i]);
      } else {
        // This step is EXTREMELY important!
        if (storage.empty()) return false;
        switch (s[i]) {
          case '}':
            if (storage.top() == '{') {
              storage.pop();
            } else
              return false;
            break;
          case ')':
            if (storage.top() == '(') {
              storage.pop();
            } else
              return false;
            break;
          case ']':
            if (storage.top() == '[')
              storage.pop();
            else
              return false;
            break;
        }
      }
    }
    return storage.empty();
  }
};
