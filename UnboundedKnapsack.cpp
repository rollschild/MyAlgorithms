#include <iostream>
#include <cstring>
using namespace std;
// bottom up manner
int dp(int W, int n, int wt[], int val[]) {
    int weight[W+1];
    memset(weight, 0, sizeof(weight));
    for(int w = 0; w <= W; ++w) { // loop through the weight
        // although w is cap remaining, we need to loop w from 0 to W, not 
        // in the reverse order
        // maybe it's correct this time
        for(int i = 0; i < n; ++i) {
            if(wt[i] <= w) {
               weight[w] = max(weight[w], val[i] + weight[w-wt[i]]);
            }
        }
    }
    return weight[W];
}

int main() {
    int limit = 100;
    int wt[] = {5, 10, 15};
    int val[] = {10, 30, 20};
    int n = sizeof(wt)/sizeof(wt[0]);
    cout << dp(limit, n, wt, val) << endl;
    return 0;
}
