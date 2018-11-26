class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int max_abs = 0;
    for (int i = 0; i < prices.size(); ++i) {
      int max_tmp = *max_element(prices.begin() + i, prices.end());
      max_abs = max(max_tmp - prices[i], max_abs);
    }

    return max_abs;
  }
};
