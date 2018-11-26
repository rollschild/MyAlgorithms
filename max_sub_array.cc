class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    if (size == 1) return nums[0];
    int current_sum = nums[0];
    int total_sum = nums[0];
    for (int i = 1; i < size; ++i) {
      current_sum = max(current_sum + nums[i], nums[i]);
      total_sum = max(total_sum, current_sum);
    }
    return total_sum;
  }
};
