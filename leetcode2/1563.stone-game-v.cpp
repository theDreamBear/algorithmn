/*
 * @lc app=leetcode.cn id=1563 lang=cpp
 * @lcpr version=30204
 *
 * [1563] 石子游戏 V
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
    int stoneGameV(vector<int>& piles) {
        int n = piles.size();
        if (n <= 1) return 0;
        int sum[1000]{};
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + piles[i];
        }
        vector<vector<int>> dp(1000, vector<int>(1000, -1));
        auto dfs = [&](auto&& dfs, int l, int r) {
            if (l >= r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            int v = (sum[r + 1] - sum[l]);
            int res = 0;
            for (int k = l; k < r; k++) {
                int lv = sum[k + 1] - sum[l];
                int rv = v - lv;
                if (lv == rv) {
                    res = max(res, lv + max(dfs(dfs, l, k), dfs(dfs, k + 1, r)));
                } else if (lv < rv) {
                    res = max(res, dfs(dfs, l, k) + lv);
                } else {
                    res = max(res, dfs(dfs, k + 1, r) + rv);
                }
            }
            return dp[l][r] = res;
        };
        return dfs(dfs, 0, n - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,3,4,5,5]\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4]\n
// @lcpr case=end

 */

