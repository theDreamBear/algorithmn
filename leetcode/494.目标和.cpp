/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
 public:
    int rightOneIndex(unsigned int val) {
        if (val == 0) {
            return 32;
        }
        return __builtin_ffs(val) - 1;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sz = 1 << nums.size();
        unsigned int sum[sz];
        sum[0] = accumulate(nums.begin(), nums.end(), 0);
        int ans = 0;
        if (sum[0] == target) {
            ++ans;
        }
        for (int mask = 1; mask < sz; ++mask) {
            int pos = rightOneIndex(mask);
            int s = sum[mask ^ (1 << pos)] - 2 * nums[pos];
            sum[mask] = s;
            if (s == target) {
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

