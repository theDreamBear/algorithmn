/*
 * @lc app=leetcode.cn id=322 lang=cpp
 * @lcpr version=30114
 *
 * [322] 零钱兑换
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
    /*
        1 <= coins.length <= 12
        1 <= coins[i] <= 2^31 - 1
        0 <= amount <= 10^4

        定义: dp[i][j]
        状态： 前i个凑齐j的金额，最少的银币数
        初始化：dp[0][0] = 0, dp[0][1...] = -1; dp[1...][0] = 0;
        状态转移
            dp[i][j] = dp[i - 1][j];
            if (j > coins[i - 1]) {
                dp[j][j] = min(dp[i][j], dp[i][j - coins[i]] + 1));
            }
        结果： dp[n][amount];

    */
    int coinChange1(vector<int>& coins, int amount) {
        // 这是一个完全背包问题
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 100000));
        for (int i = 0; i < coins.size() + 1; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i < coins.size() + 1; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i -1]) {
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
        int val = dp.back().back();
        if (val >= 100000) {
            return -1;
        }
        return val;
    }

    /*
        滚动数组
    */
    int coinChange(vector<int>& coins, int amount) {
        // 这是一个完全背包问题
        vector<int> dp(amount + 1, 100000);
        dp[0] = 0;
        for (int i = 1; i < coins.size() + 1; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i -1]) {
                    dp[j] = min(dp[j], dp[j - coins[i - 1]] + 1);
                }
            }
        }
        int val = dp.back();
        if (val >= 100000) {
            return -1;
        }
        return val;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1, 2, 5]\n11\n
// @lcpr case=end

// @lcpr case=start
// [2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1]\n0\n
// @lcpr case=end

 */

