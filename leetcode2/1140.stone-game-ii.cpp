 /*
 * @lc app=leetcode.cn id=1140 lang=cpp
 * @lcpr version=30204
 *
 * [1140] 石子游戏 II
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
    int stoneGameII(vector<int>& piles) {
        int sum[200]{};
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + piles[i];
        }
        int dp[200][200]{};
        auto dfs= [&](auto&& dfs, int i, int m)->int {
            if (i + 2 * m >= n) {
                return sum[n] - sum[i];
            }
            if (dp[i][m]) return dp[i][m];
            int res = 0;
            for (int j = 1; j <= 2 * m and i + j < n; j++) {
                res = max(res,  - sum[i] + sum[n] -  dfs(dfs, i + j, max(m, j)));
            }
            return dp[i][m] = res;
        };
        return dfs(dfs, 0, 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,9,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5,100]\n
// @lcpr case=end

 */

