#include <iostream>

using namespace std;

void func(int arr[], int sum, int l) {
    int startpos = 0;
    int currsum = arr[startpos];
    int endpos;
    for(endpos = startpos + 1; endpos < l; ++endpos) {
        while(currsum > sum && startpos < endpos) {
            currsum -= arr[startpos];
            ++startpos;
        }
        /*
        if(currsum > sum && startpos >= endpos) {
            cout << "No subarray found." << endl;
            return;
        }
        */
        if(currsum == sum && startpos <= endpos) {
            cout << "We found the first subarray! " << endl;
            cout << "Index between " << startpos << " and " << endpos-1 << endl;
            break;
        }
        if(currsum < sum && startpos <= endpos) {
            currsum += arr[endpos];
        }
    }
    if(currsum != sum) {
        cout << "No subarray found." << endl;
    }
    return;
}

int main() {
    // int arr[] = {1, 4, 20, 3, 10, 5};
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    // int arr[] = {1, 4, 0, 0, 3, 10, 5};
    int sum = 23;
    int l = sizeof(arr) / sizeof(arr[0]);
    func(arr, sum, l);
    return 0;
}
