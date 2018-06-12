#include <iostream>
#include <map>
#include <vector>
using namespace std;

void func(int arr[], int l) {
    map<int, bool> ele;
    map<int, bool>::iterator itr;
    vector<int> vec;
    for(int i = 0; i < l; ++i) {
        int e = arr[i];
        itr = ele.find(e);
        if(itr != ele.end()) {
            ele[e] = false;
        }
        else {
            ele[e] = true;
        }
    }
    for(itr = ele.begin(); itr != ele.end(); ++itr) {
        if(itr->second == true) {
            vec.push_back(itr->first);
            itr->second = false;
        }
    }
    cout << vec[0] << " " << vec[1] << endl;
    return;
}

int main() {
    // int arr[] = {2, 3, 7, 9, 11, 2, 3, 11};
    int arr[] = {2, 4, 7, 9, 2, 4};
    int l = sizeof(arr) / sizeof(arr[0]);
    func(arr, l);
    return 0;
}
