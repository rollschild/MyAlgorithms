class Solution {
public:
    void permutation(vector<int>& nums, vector<int>& temp, vector<vector<int>>& results) {
        if (temp.size() == nums.size()) results.push_back(temp);
        
        for(int i = 0; i < nums.size(); ++i) {
            if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                // num already chosen
                continue;
            }
            temp.push_back(nums[i]);
            permutation(nums, temp, results);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> temp;
        permutation(nums, temp, results);
        return results;
    }
};
