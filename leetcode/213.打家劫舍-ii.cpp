/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
    /*
        可以用滚动数组加速
    */
    int rob1(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        // 不取头
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        // nums[1:n - 1]
        for (int i = 2; i < nums.size() + 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        // 取头
        vector<int> dp2(nums.size());
        dp2[0] = 0;
        dp2[1] = nums[0];
        dp2[2] = nums[0];
        for (int i = 3; i < nums.size(); ++i) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        }
        return max(dp.back(), dp2.back());
    }

    int robRange(const vector<int>& nums, int start, int end) {
        int prepre = 0;
        int pre = nums[start];
        for (int i = start + 1; i <= end; ++i) {
            int cur = max(pre, prepre + nums[i]);
            prepre = pre;
            pre = cur;
        }
        return pre;
    }

    /*
        这个题可以多理解会
    */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};
// @lc code=end
