class Solution {
public:
    int longestValidParentheses(string s) {
        // array<int, s.length()> arr(0);
        vector<int> arr(s.size(), 0);
        // int arr[s.length()] = {0};
        if (s.size() == 0) return 0;
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (i > 0 && s[i - 1] == '(') {
                    arr[i] += 2 + (i >= 2 ? (arr[i - 2]) : 0);
                }
                
                if (i > 0 && s[i - 1] == ')') {
                    if ((i >= arr[i - 1] + 1) && s[i - arr[i - 1] - 1] == '(') {
                        arr[i] += 2 + arr[i - 1] + ((i >= arr[i - 1] + 2) ? arr[i - arr[i - 1] - 2] : 0);
                    }
                }
            }
        }
        return *max_element(arr.begin(), arr.end());
    }
};
