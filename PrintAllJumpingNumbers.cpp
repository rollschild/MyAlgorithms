#include <iostream>
#include <vector>

using namespace std;

void func(int arr[], int l) {
    vector<int> vec;
    for(int i = 0; i < l; ++i) {
        int element = arr[i];
        if(element < 10) {
            vec.push_back(element);
            continue;
        }


    }
}
