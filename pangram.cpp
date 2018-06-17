/*
 * Vector is used to store appearences of each letter because it's more flexible than normal array.
 * Function isPangram() is defined and implemented outside of the main function so that it's more
 * portable and modular and in the future it can be included in another header file.
 * I use cin to give you an option to type in the string you want to test.
 */


#include <iostream>
#include <vector>

using namespace std;

bool isPangram(string s) {
    // In case string is empty
    if(s.length() == 0) {
        return false;
    }
    
    // alphabet is used to store the appearence of each letter that exists in this string
    vector<int> alphabet(26, 0);

    // loop through the string
    for(int i = 0; i < s.length(); ++i) {
        // In this case, it should not be case sensitive
        char c = s[i];
        if(c <= 90) {
            // Caps
            alphabet[c-65]++;
        }
        else {
            // Lower cases
            alphabet[c-97]++;
        }
    }

    for(auto num : alphabet) {
        // if one letter does not exist in the string, return false right away
        if(num == 0) return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    if(isPangram(s)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
