#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// here we assume only alphaets
bool isWithinLimit(int count[], int num) {
    int val = 0;
    for(int i = 0; i < 26; ++i) {
        if(count[i] > 0) {
            ++val;
        }
    }
    return (val <= num);
}

void func(string str, int l, int k) {
    if(l == 0 || k == 0) {
        cout << 0 << endl;
        return;
    }
    int begin = 0;
    int max_begin = begin;
    int end;
    int window = 1;
    int count[26];
    int num = 0;
    memset(count, 0, sizeof(count));
    for(char c : str) {
        if(count[c - 'a'] == 0) {
            ++num;
        }
        ++count[c - 'a'];
    }
    if(num < k) {
        cout << "Not enough unique characters. Exiting... " << endl;
        return;
    }
    // use substr(), you stupid fuck!
    memset(count, 0, sizeof(count));
    ++count[str[begin]-'a'];
    for(end = begin + 1; end < l; ++end) {
        ++count[str[end] - 'a'];
        while(!isWithinLimit(count, k)) {
            --count[str[begin] - 'a'];
            ++begin;
        }
        if((end - begin + 1) > window) {
            window = end - begin + 1;
            max_begin = begin;
        }
    }
    cout << "Max substring is " << str.substr(max_begin, window) << " with length " << window << endl;
    return;
}


int main() {
    // string str = "aabbcc";
    string str = "aabacbebebe";
    int k = 3;
    int l = str.length();
    func(str, l, k);
    return 0;
}
