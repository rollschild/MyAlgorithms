/*
")()())" 
max_len = 4
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> indices{};
        indices.push(-1);
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                indices.push(i);
            }
            else {
                indices.pop();
                if (indices.empty()) {
                    indices.push(i);
                }
                else {
                    int index = indices.top();
                    max_len = max(max_len, i - index);
                }
            }
        }
        return max_len;
    }
};
