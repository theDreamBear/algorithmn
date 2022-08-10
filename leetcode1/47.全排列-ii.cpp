/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        function<void(int)> backtrack = [&](int pos) {
            if (pos >= nums.size()) {
                ans.push_back(nums);
                return;
            }
            unordered_set<int> visited;
            for (int i = pos; i < nums.size(); i++) {
                if (visited.count(nums[i])) {
                    continue;
                }
                visited.insert(nums[i]);
                swap(nums[i], nums[pos]);
                backtrack(pos + 1);
                swap(nums[i], nums[pos]);
            }
        };
        backtrack(0);
        return ans;
    }
};
// @lc code=end

