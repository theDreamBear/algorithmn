/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> backtrack = [&](int pos, int curSum) {
            if (curSum > target) {
                return;
            }
            if (curSum == target) {
                ans.push_back(temp);
                return;
            }
            for (int i = pos; i < candidates.size() && curSum + candidates[i] <= target; i++) {
                if (i > pos && candidates[i - 1] == candidates[i]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                backtrack(i + 1, curSum + candidates[i]);
                temp.pop_back();
            }
        };
        backtrack(0, 0);
        return ans;
    }
};
// @lc code=end

