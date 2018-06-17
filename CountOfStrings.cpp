#include <iostream>
#include <cstring>
using namespace std;

// int array must have bounds except for the first dimension
int countString(int dp[][2][3], int n, int num_b, int num_c) {
    if(num_b < 0 || num_c < 0) {
        return 0;
    }
    if(n == 0) return 1;
    if(num_b == 0 && num_c == 0) {
        return 1;
    }

    if(dp[n][num_b][num_c] != -1) {
        return dp[n][num_b][num_c];
    }
    /*
    int counts = countString(dp, n-1, num_b, num_c);
    counts += countString(dp, n-1, num_b-1, num_c);
    counts += countString(dp, n-1, num_b, num_c-1);
    return dp[n][num_b][num_c] = counts;
    */
    return dp[n][num_b][num_c] = countString(dp, n-1, num_b, num_c) + 
        countString(dp, n-1, num_b-1, num_c) + countString(dp, n-1, num_b, num_c-1);
}

int main() {
    
    int n = 0;
    int bCount = 1;
    int cCount = 2;
    
    cin >> n;
    int dp[n+1][2][3];
    memset(dp, -1, sizeof(dp));
    cout << countString(dp, n, bCount, cCount) << endl;
    return 0;
}
