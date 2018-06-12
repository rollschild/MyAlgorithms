#include <iostream>
#include <cstring>
using namespace std;
// bottom up method
// dynamic programming
int packing(int weight, int val[], int wt[], int n) {
    int stuff[n+1][weight+1];
    int i;
    int w;
    memset(stuff, 0, sizeof(stuff));
    for(i = 0; i <= n; ++i) {
        // here w is the remaining capacity
        for(w = weight; w >= 0; --w) {
            if(i == 0 || w ==0) {
                stuff[i][w] = 0;
            }
            else if(wt[i-1] <= w) {
                // the wt[i-1] is either in the optimal solution, or not
                stuff[i][w] = max(val[i-1] + stuff[i-1][w-wt[i-1]], stuff[i-1][w]);
            }
            else {
                stuff[i][w] = stuff[i-1][w];
            }
        }
    }
    return stuff[n][weight];
}

int main() {
    int value[] = {60, 100, 120};
    int size[] = {10, 20, 30};
    int W = 50;
    int n = 3;
    cout << packing(W, value, size, 3) << endl;
    return 0;
}
