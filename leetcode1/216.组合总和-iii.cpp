/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        function<void(int, int)> backtrack = [&](int val, int sum) {
            if (sum == n && temp.size() == k) {
                ans.push_back(temp);
                return;
            }
            if (sum > n || val > 9 || temp.size() > k) {
                return;
            }
            for (int i = val; i < 10 && sum + i <= n; i++) {
                temp.push_back(i);
                backtrack(i + 1, sum + i);
                temp.pop_back();
            }
        };
        backtrack(1, 0);
        return ans;
    }
};
// @lc code=end

