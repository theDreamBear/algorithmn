/*
 * @lc app=leetcode.cn id=3250 lang=cpp
 * @lcpr version=30204
 *
 * [3250] 单调数组对的数目 I
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
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int countOfPairs1(vector<int>& nums) {
        int n = nums.size();
        int m = ranges::max(nums);
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(m + 1, INT_MIN));
        auto dfs = [&](auto&& dfs, int i, int c) {
            if (i >= n) return 1;
            if (dp[i][c] != INT_MIN) return dp[i][c];
            int res = 0;
            int pre = i == 0 ? INT_MAX : nums[i - 1] - c;
            for (int v = max(c, nums[i] - pre); v <= nums[i]; v++) {
                res = (res + dfs(dfs, i + 1, v)) % mod;
            }
            return dp[i][c] = res;
        };
        return dfs(dfs, 0, 0);
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int m = ranges::max(nums);
        int mod = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(m + 1, 0));
        for (int v = 0; v <= nums[0]; v++) {
            dp[0][v] = 1;
        }
        int ft = 0, st = 1;
        for (int i = 1; i < n; i++) {
            for (int c = 0; c <= nums[i]; c++) {
                dp[st][c] = 0;
                for (int p = 0; p <= min(c, nums[i - 1] - nums[i] + c); p++) {
                    dp[st][c] = (dp[st][c] + dp[ft][p]) % mod;
                }
            }
            swap(st, ft);
        }
        int res = 0;
        for (int i = 0; i <= nums.back(); i++) {
            res = (res + dp[ft][i]) % mod;
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5,5]\n
// @lcpr case=end

 */

