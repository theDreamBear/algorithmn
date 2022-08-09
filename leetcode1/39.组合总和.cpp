/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int, int)> backtrack = [&](int pos, int curSum) {
            if (curSum > target) {
                return;
            }
            if (curSum == target) {
                ans.push_back(temp);
                return;
            }
            for (int i = pos; i < candidates.size() && curSum + candidates[i] <= target; i++) {
                if (i > pos && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                temp.push_back(candidates[i]);
                backtrack(i, curSum + candidates[i]);
                temp.pop_back();
            }
        };
        backtrack(0, 0);
        return ans;
    }
};
// @lc code=end

