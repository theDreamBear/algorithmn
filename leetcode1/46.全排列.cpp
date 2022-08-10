/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> temp = nums;
        function<void(int)> backtrack = [&](int pos) {
            if (pos >= nums.size()) {
                ans.push_back(temp);
                return;
            }
            for (int i = pos; i < nums.size(); i++) {
                swap(temp[i], temp[pos]);
                backtrack(pos + 1);
                swap(temp[i], temp[pos]);
                //backtrack(i + 1);
            }
        };
        backtrack(0);
        return ans;
    }
};
// @lc code=end

