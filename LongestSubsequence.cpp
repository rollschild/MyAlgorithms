// two sub problems:
// is string1 a sub sequence of string2
// find the longes string



#include <iostream>
#include <vector>

using namespace std;

bool isSub(string sub, string parent) {
    int l1 = sub.length();
    int l2 = parent.length();
    int j = 0;
    for(int i = 0; j < l1 && i < l2; ++i) {
        if(sub[j] == parent[i]) {
            ++j;
        }
    }
    return j == l1;
}

string findLongestSub(vector<string> arr, string str) {
    int l = 0;
    string result = "";
    for(string word : arr) {
        if(isSub(word, str)) {
            result = word.length() > result.length() ? word : result;
        }
    }
    return result;
}

int main() {
    vector<string> arr = {"pintu", "geeksfor", "geeksgeeks", "forgeek"};
    string str = "geeksforgeeks";
    cout << findLongestSub(arr, str) << endl;
    return 0;
}
