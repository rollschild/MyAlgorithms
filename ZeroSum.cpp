// find all triplets with zeor sum
// Double-Pointer technique
// time: O(n^2)
// space: O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void ZeroSum(int arr[], int n) {
    sort(arr, arr + n);
    bool found = false;
    for(int i = 0; i <= n - 2; ++i) {
        int pivot = arr[i];
        int l = i+1;
        int r = n - 1;
        while(l < r) {
            if(pivot + arr[l] + arr[r] == 0) {
                found = true;
                cout << pivot << " " << arr[l] << " " << arr[r] << endl;
                ++l;
                ++r;
            }
            else if(pivot + arr[l] + arr[r] < 0) {
                ++l;
            }
            else --r;
        }
    }

    if(found == false) {
        cout << "No triplets found. " << endl;
    }

}

int main() {
    int arr[] = {0, -1, 2, -3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    ZeroSum(arr, n);
    return 0;
}
