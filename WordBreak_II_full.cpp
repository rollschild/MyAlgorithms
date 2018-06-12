#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        string temp = "";
        int leftpos = 0;
        bool initial = true;
        int initial_length = 1;
        int rightpos = leftpos + initial_length - 1;
        while(rightpos < s.length()) {
            // if(leftpos == s.length-1) break;
            // int rightpos = leftpos+initial_length-1;
            string sub = s.substr(leftpos, rightpos-leftpos+1);
            // cout << sub << endl;
            if(find(wordDict.begin(), wordDict.end(), sub) != wordDict.end()) {
                if(initial) {
                    // the first match
                    initial_length = rightpos - leftpos + 1;
                    initial = false;
                } // initial_length = 3;
                // string occurs in the vector/dictionary
                if(rightpos == (s.length() - 1)) {
                    // end of string
                    // need to restart
                    temp += sub;
                    result.push_back(temp);
                    cout << temp << endl;
                    if(rightpos-leftpos+1 >= s.length()) break;
                    leftpos = 0;
                    ++initial_length;
                    rightpos = leftpos + initial_length - 1;
                    temp = "";
                }
                else {
                    temp += sub;
                    temp += " ";
                    cout << temp << endl;
                    leftpos = rightpos + 1;
                    rightpos = leftpos;
                }
            }
            // now if rightpos not reaching end of string
            else if(rightpos < (s.length()-1)) {
                ++rightpos;
            }
            // if rightpos is already end of string
            else {
                temp = "";
                if(rightpos-leftpos+1 >= s.length()) break;
                leftpos = 0;
                ++initial_length;
                rightpos = leftpos + initial_length - 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> dict = {"aaaa", "aaa"};
    vector<string> vec = solution.wordBreak("aaaaaaa", dict);
    for(auto v : vec) {
        cout << v << endl;
    }
    return 0;
}
