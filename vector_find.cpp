#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<string> vec = {"aaaa", "aaa"};
    string a = "aaa";
    vector<string>::iterator itr;
    itr = find(vec.begin(), vec.end(), a);
    if(itr != vec.end()) cout << *itr << endl;
    else cout << "nope" << endl;
    return 0;
}
