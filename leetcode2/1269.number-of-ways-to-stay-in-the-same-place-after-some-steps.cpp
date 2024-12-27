/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 * @lcpr version=30204
 *
 * [1269] 停在原地的方案数
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
#include <string.h>
// @lcpr-template-end
// @lc code=start
const int mod = 1e9 + 7;
class Solution {
public:
    int numWays_dfs(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        auto dfs = [&](auto&& dfs, int pos, int left)->int {
            if (left == 0) {
                return pos == 0;
            }
            // 打死回不去了, 直接返回
            if (pos - left > 0) {
                return 0;
            }
            auto& ans = dp[pos][left];
            if (ans != -1) {
                return ans;
            }
            // 待着不动
            ans = dfs(dfs, pos, left -1);
            if (pos) {
                ans = (ans + dfs(dfs, pos - 1, left - 1)) % mod;
            }
            if (pos + 1 < arrLen) {
                ans = (ans + dfs(dfs, pos + 1, left - 1)) % mod;
            }
            return ans;
        };
        return dfs(dfs, 0, steps);
    }

    int numWays1(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 2, vector<int>(steps + 2, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= i; j++) {
                for (auto k: {-1, 0, 1}) {
                    if (j + k >= 0 and j + k < arrLen) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j + k]) % mod;
                    }
                }
            }
        }
        return dp[steps][0];
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(2, vector<int>(steps + 2, 0));
        dp[0][0] = 1;
        int ft = 0, st = 1;
        for (int i = 1; i <= steps; i++) {
            // 初始为0
            //fill(dp[st].begin(), dp[st].end(), 0);
            for (int j = 0; j <= i; j++) {
                dp[st][j] = 0;
                for (auto k: {-1, 0, 1}) {
                    if (j + k >= 0 and j + k < arrLen) {
                        dp[st][j] = (dp[st][j] + dp[ft][j + k]) % mod;
                    }
                }
            }
            swap(ft, st);
        }
        return dp[ft][0];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 3\n2\n
// @lcpr case=end

// @lcpr case=start
// 2\n4\n
// @lcpr case=end

// @lcpr case=start
// 4\n2\n
// @lcpr case=end

 */

