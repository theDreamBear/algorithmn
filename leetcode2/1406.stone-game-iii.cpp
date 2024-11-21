/*
 * @lc app=leetcode.cn id=1406 lang=cpp
 * @lcpr version=30204
 *
 * [1406] 石子游戏 III
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
    string stoneGameIII_dfs(vector<int>& stoneValue) {
        int n = stoneValue.size();
        // int sum[n + 100];
        // sum[n] = 0;
        // for (int i = n - 1; i >= 0; i--) {
        //     sum[i] = sum[i + 1] + stoneValue[i];
        // }
        int dp[n + 100];
        fill(dp, dp + n + 100, INT_MAX);
        auto dfs = [&](auto&& dfs, int i) {
            if (i >= n) return 0;
            if (dp[i] != INT_MAX) return dp[i];
            int res = INT_MIN;
            int v = 0;
            for (int j = 1; j <= 3 and i + j <= n; j++) {
                v += stoneValue[i + j - 1];
                res = max(res, v - dfs(dfs, i + j));
            }
            return dp[i] = res;
        };
        int res = dfs(dfs, 0);
        return res > 0 ? "Alice": res < 0 ? "Bob": "Tie";
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[n + 100];
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = INT_MIN;
            int v = 0;
            for (int j = 1; j <= 3 and i + j <= n; j++) {
                v += stoneValue[i + j - 1];
                dp[i] = max(dp[i], v - dp[i + j]);

            }
        }
        int res = dp[0];
        return res > 0 ? "Alice": res < 0 ? "Bob": "Tie";
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,-9]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,6]\n
// @lcpr case=end

 */

