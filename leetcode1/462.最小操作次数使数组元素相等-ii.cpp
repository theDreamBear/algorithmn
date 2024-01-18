/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最小操作次数使数组元素相等 II
 */

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int l = (n - 1) >> 1;
        for (auto v : nums) {
            ans += abs(v - nums[l]);
        }
        return ans;
    }
};
// @lc code=end

