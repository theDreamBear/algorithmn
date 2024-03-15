/*
 * @lc app=leetcode.cn id=LCR 102 lang=cpp
 * @lcpr version=30119
 *
 * [LCR 102] 目标和
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    // 超时
    int findTargetSumWays_bad(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < (1 << n); i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    sum += nums[j];
                } else {
                    sum -= nums[j];
                }
            }
            if (sum == target) {
                ++ans;
            }
        }
        return ans;
    }

    /*
        状态压缩
    */
    int findTargetSumWays_compress(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        // 0 取正， 1 取负数
        vector<int> dp(1 << n);
        dp[0] = accumulate(nums.begin(), nums.end(), 0);
        if (dp[0] == target) {
            ++ans;
        }
        for (int i = 1; i < (1 << n); i++) {
            int pos = __builtin_ffs(i) - 1;
            if ((dp[i] = dp[i ^ (1 << pos)] - 2 * nums[pos]) == target) {
                ++ans;
            }
        }
        return ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = 0;
        int ans = 0;
        vector<vector<int>> dp(2, vector<int>(2001));
        dp[idx % 2][1000] = 1;
        for (int i = 0; i < n; i++) {
            ++idx;
            for (int j = 0; j < 2001; j++) {
                dp[idx % 2][j] = 0;
                if (j - nums[i] >= 0 && dp[(idx - 1) % 2][j - nums[i]]) {
                    dp[idx % 2][j] += dp[(idx - 1) % 2][j - nums[i]];
                }
                if (j + nums[i] <= 2000 && dp[(idx - 1) % 2][j + nums[i]]) {
                    dp[idx % 2][j] += dp[(idx - 1) % 2][j + nums[i]];
                }
            }
        }
        return dp[idx % 2][target + 1000];
    }

    // 看答案， 有一个比较有意思的解法
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,1,1,1]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

