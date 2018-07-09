class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        // used.resize(nums.size());
        permutationUnique(nums, temp, used, results);
        return results;    
    }
    
    void permutationUnique(
        vector<int>& nums, 
        vector<int>& temp, 
        vector<bool>& used, 
        vector<vector<int>>& results) {
        if (temp.size() == nums.size()) {
            results.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            permutationUnique(nums, temp, used, results);
            used[i] = false;
            temp.pop_back();
        }
    }  
};
