class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount < 1) return 0;
    if (coins.size() == 0) return -1;
    vector<int> dp(amount, 0);
    return check(coins, amount, dp);
  }

  int check(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) return 0;
    if (amount < 0) return -1;
    if (dp[amount - 1] != 0) return dp[amount - 1];
    int min_value = amount + 1;
    for (auto value : coins) {
      int res = check(coins, amount - value, dp);
      if (res >= 0 && res < min_value) min_value = res + 1;
    }
    dp[amount - 1] = (min_value > amount) ? -1 : min_value;
    return dp[amount - 1];
  }
};
