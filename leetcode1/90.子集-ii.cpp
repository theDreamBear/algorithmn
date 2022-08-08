/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int)> dfs = [&](int pos) {
            ans.push_back(temp);
            if (pos >= nums.size()) {
                return;
            }
            for (int i = pos; i < nums.size(); i ++) {
                if (i > pos && nums[i - 1] == nums[i]) {
                    continue;
                }
                temp.push_back(nums[i]);
                dfs(i + 1);
                temp.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

