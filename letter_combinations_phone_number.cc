class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    map<char, vector<char>> dict = {
        {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
    };

    vector<string> collection{};
    if (digits.length() != 0) helper(digits, collection, dict, "");
    return collection;
  }

  void helper(string digits, vector<string>& collection,
              map<char, vector<char>>& dict, string memo) {
    if (digits.length() == 0) {
      if (find(collection.begin(), collection.end(), memo) ==
          collection.end()) {
        collection.push_back(memo);
        return;
      }
    }

    char s = digits[0];
    for (int j = 0; j < dict[s].size(); ++j) {
      // memo += dict[s][j];
      helper(digits.substr(1, digits.length() - 1), collection, dict,
             memo + dict[s][j]);
    }
  }
};
