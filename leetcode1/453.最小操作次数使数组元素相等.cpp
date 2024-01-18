/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            int mul = n - i - 1;
            int diff = nums[i + 1] - nums[i];
            ans += mul * diff;
        }
        return ans;
    }
};
// @lc code=end

